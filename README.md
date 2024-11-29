# Smart-Step-Safety-System
Smart Step Safety System
          The Smart Step Safety System enhances passenger safety in buses by monitoring step occupancy and implementing corrective actions to reduce risks during transit. It employs pressure sensors, an alert mechanism, and motor speed control to enforce safety measures effectively.

Features
          Step Monitoring: Detects if a passenger stands on the bus steps.
          Buzzer Alert: Activates an audible alert if a passenger stands on the steps beyond a safe period.
          Speed Reduction: Reduces the bus motor speed when the passenger continues to stand on the steps after the alert.
          Safety Optimization: Helps prevent accidents by discouraging unsafe standing on steps during transit.
Components Used
          FSR (Force Sensitive Resistor): Detects pressure when a passenger stands on the step.
          Arduino Board: Processes sensor data and controls actions.
          Buzzer: Provides an audible alert when the threshold is exceeded.
          DC Motor and Motor Driver: Simulates bus movement and adjusts speed.
          Battery Holder with Two 3.7V Batteries: Powers the system.
          Cardboard Model: Represents the bus structure.
          Additional Components: Wires, resistors, and a voltage divider circuit for the FSR sensor.
Working Process
          1. Setup:
                An FSR sensor is embedded under the bus steps to detect pressure from passengers.
                The sensor is connected to the Arduino via a voltage divider circuit, ensuring accurate pressure readings.
          2. Step Detection:
              When pressure is detected on the step:
                The system initially activates an audible buzzer alert to prompt the passenger to move away.
                If the passenger remains on the step after the alert, the system reduces the bus motor's speed to enhance safety.
          3. Motor Speed Adjustment:
                A DC motor is used to simulate the bus's movement.
                The motor driver reduces the motor's speed when the passenger persists in standing on the step after the alert.
          4. Reset Mechanism:
                The system resets automatically when the pressure on the FSR sensor is released, allowing the motor to return to its normal speed.
Testing and Validation
          FSR Sensor Sensitivity:
                Tested with varying pressure levels (e.g., finger pressure and actual foot pressure) to ensure accurate detection.
          Buzzer Functionality:
                Verified the buzzer activates after step occupancy exceeds a safe duration.
          Motor Speed Control:
                Ensured the motor speed reduces effectively during extended step occupancy.
          Power Management:
                Confirmed consistent operation using two 3.7V batteries.
Conclusion
          The Smart Step Safety System improves passenger safety by providing timely alerts and reducing vehicle speed when safety rules are violated. It is a cost-effective and efficient solution for urban transportation systems.
