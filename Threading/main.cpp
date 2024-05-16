#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <thread>

// This queue is used to store all of the data produced
std::queue<int> buffer;

// This mutex is used to control the locking and unlocking of the queue
std::mutex buffer_mutex;

std::condition_variable buffer_cv;

bool done = false;

void spaceshipProducer(int id, int num_items) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 100);
  std::uniform_int_distribution<> sleep(50, 150);

  // We need to make an iteration for every item the producer will generate
  for (int i = 0; i < num_items; ++i) {
    int item = dis(gen);

    // Critical section starts here
    {
      // Lock the mutex to protect access to the shared buffer
      std::lock_guard<std::mutex> lock(buffer_mutex);
      // Add item to the buffer
      buffer.push(item);
      std::cout << "Producer " << id << " produced " << item << std::endl;
    } // The lock is automatically released here at the end of the scope

    // Notify one of the waiting consumer threads that a new item is available
    buffer_cv.notify_one();

    // Simulate some delay between producing items
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep(gen)));
  }
}

void spaceshipConsumer(int id) {
  // Infinitely wait for buffer items to consume
  while (true) {
    // Create a unique_lock for access to the buffer
    std::unique_lock<std::mutex> lock(buffer_mutex);

    // Wait until there is data in the buffer or all producers are done
    buffer_cv.wait(lock, [] { return !buffer.empty() || done; });

    // Check if an item can be taken off the queue or end program
    if (!buffer.empty()) {
      // Consume item from the buffer
      int item = buffer.front();
      buffer.pop();
      std::cout << "Consumer " << id << " consumed " << item << std::endl;
    } else if (done) {
      // End program if all producers are done and buffer is empty
      break;
    }
  }
}

int main() {

    const int num_producers = 3;
    const int num_consumers = 3;
    const int num_items_per_producer = 10;

    // Create and start producer threads
    std::vector<std::thread> producers;
    for (int i = 0; i < num_producers; ++i) {
        producers.emplace_back(spaceshipProducer, i + 1, num_items_per_producer);
    }

    // Create and start consumer threads
    std::vector<std::thread> consumers;
    for (int i = 0; i < num_consumers; ++i) {
        consumers.emplace_back(spaceshipConsumer, i + 1);
    }

    // Join producer threads
    for (auto& producer : producers) {
        producer.join();
    }

    // Notify consumers that production is done
    {
        std::lock_guard<std::mutex> lock(buffer_mutex);
        done = true;
    }
    buffer_cv.notify_all();

    // Join consumer threads
    for (auto& consumer : consumers) {
        consumer.join();
    }

    return 0;
}
