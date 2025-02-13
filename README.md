# Dining Philosophers Problem

The Dining Philosophers Problem is a classic synchronization and concurrency problem in computer science, introduced by Edsger Dijkstra in 1965. It illustrates the challenges of resource allocation and deadlock avoidance in a multi-process system. This problem is particularly relevant in the context of threading and shared memory, as it involves multiple threads (philosophers) competing for shared resources (forks) while avoiding deadlock and starvation.
![dining_philosopher_problem](https://github.com/user-attachments/assets/c8b15bba-b9ae-43ed-b888-7671084f45c1)

## Project Overview: Philosophers
This project focuses on the basics of threading and working with shared memory. The goal is to simulate the Dining Philosophers Problem using threads and mutexes to ensure that philosophers can eat, think, and sleep without running into synchronization issues like deadlock or starvation.

![download](https://github.com/user-attachments/assets/174e3842-59dc-448d-bd75-55acc067ba55)

## Problem Description:
- Philosophers: A number of philosophers sit at a round table, alternating between eating, thinking, and sleeping.
- Forks: There is one fork between each pair of philosophers. Since spaghetti is difficult to eat with one fork, each philosopher needs two forks (one on their left and one on their right) to eat.

- Constraints:
  - Philosophers must never starve.
  - Philosophers cannot communicate with each other.
  - The simulation stops if a philosopher dies (fails to eat within a specified time).
  - Each fork is a shared resource and must be protected by a mutex to prevent race conditions.
 
Key Challenges:
1. Deadlock: If all philosophers pick up their left fork simultaneously, they will all wait indefinitely for the right fork, causing a deadlock.
2. Starvation: Some philosophers might starve if others monopolize the forks.
3. Resource Sharing: Forks are shared resources, and their state must be protected using mutexes.

Project Requirements:
### 1. Input Parameters:
   - `number_of_philosophers`: The number of philosophers (and forks).
   - `number_of_philosophers`: The number of philosophers (and forks).
   - `time_to_die`: The maximum time a philosopher can go without eating before dying.
   - `time_to_eat`: The time it takes for a philosopher to eat.
   - `time_to_sleep`: The time a philosopher spends sleeping.
   - `number_of_times_each_philosopher_must_eat (optional)`: The number of times each philosopher must eat before the simulation ends.

### 2. Rules:
   - Philosophers must never starve.
   - Each philosopher is represented by a thread.
   - Each fork is protected by a mutex.
   - The simulation stops if a philosopher dies or if all philosophers have eaten the required number of times.

### 3. Testing:
   - Do not test with more than 200 philosophers.
   - Do not test with time_to_die, time_to_eat, or time_to_sleep under 60ms.

### Example test cases:
./philo 5 800 200 200: No philosopher should die.

./philo 5 800 200 200 7: The simulation should stop when all philosophers have eaten at least 7 times.


## How to test

- These parameters are required in order when running the executable: `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `number_of_times_each_philosopher_must_eat(optional)`
- Do not test with more than 200 philosophers
- Do not test with `time_to_die` `time_to_eat` `time_to_sleep` under 60ms
- Test with `5 800 200 200`, no one should die
- Test with `5 800 200 200 7`, the simulation should stop when all the philosophers have eaten at least 7 times each

> Run the following commands:

```shell
$ git clone https://github.com/DelicaTessa/42-philosophers
$ cd 42-philosophers && philo
$ make
$ ./philo 5 800 200 200
```


#### Solutions to the Problem:
To solve the Dining Philosophers Problem in this project, you can use the following strategies:
1. Mutexes for Forks: Protect each fork with a mutex to ensure that only one philosopher can hold a fork at a time.
2. Threads for Philosophers: Represent each philosopher as a thread, allowing them to act independently.
3. Deadlock Avoidance:
   - Implement a strategy where philosophers pick up forks in a specific order (e.g., always pick up the left fork first, then the right).
   - Limit the number of philosophers trying to eat at the same time.
4. Starvation Prevention: Ensure that all philosophers get a fair chance to eat by using timeouts or scheduling mechanisms.


#### Why This Project Matters:
This project is a practical application of threading and synchronization concepts. It teaches:
- How to create and manage threads.
- How to use mutexes to protect shared resources.
- How to avoid deadlock and starvation in concurrent systems.
- How to design efficient and fair resource allocation algorithms.


