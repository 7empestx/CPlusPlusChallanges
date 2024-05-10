### OOP Challenge: Vehicle Management System

**Scenario:**
Imagine you are building a system to manage different types of vehicles for a logistics company. The company has a variety of vehicles, such as trucks, cars, motorcycles, and electric scooters, each with different characteristics and purposes.

**Your Objective:**

1. **Base Class Design:**
   - Design a base class called `Vehicle` that will serve as the parent for all vehicle types. Think about common attributes (e.g., `licensePlate`, `brand`, `modelYear`) and behaviors (e.g., `start()`, `stop()`) that can be shared across all vehicle types.

2. **Derived Classes:**
   - Design at least three derived classes from `Vehicle` representing different vehicle types (e.g., `Truck`, `Car`, `Motorcycle`, etc.).
   - Each derived class should have additional attributes and behaviors specific to that type. For instance, a truck may have a `payloadCapacity` attribute, while a motorcycle may have `sidecar` functionality.

3. **Advanced Features:**
   - Implement polymorphic behaviors for starting and stopping the vehicles. How might starting an electric scooter differ from starting a truck?
   - Add specialized methods, such as checking the fuel type, calculating load capacity, or estimating range on the remaining fuel/electric charge.

4. **Management System Class:**
   - Design a `Fleet` class that manages a collection of `Vehicle` objects.
   - Implement functionality to add new vehicles, list all vehicles, and find vehicles based on specific criteria (e.g., by license plate or vehicle type).

**Stretch Goals:**
1. Introduce an interface or abstract base class to handle vehicles with specific needs like electric-only vehicles or those that have to be climate-controlled.
2. Design additional subclasses that implement these interfaces or abstract classes to address these needs.
3. Create a `ServiceHistory` feature that tracks maintenance history for each vehicle, including the type of maintenance performed and the date.

**Final Notes:**
This challenge will help you think about how to structure your classes for maintainability and scalability. The focus should be on design principles like inheritance, encapsulation, and polymorphism. Let me know if you would like more details or hints!
