# Restaurant Reservation System (RRS)

A console-based C++ application designed to manage restaurant table bookings, customer details, menu orders, billing, and daily income tracking efficiently.

---

## 🛠️ Tech Stack & Concepts
* **Language:** C++
* **Programming Paradigm:** Object-Oriented Programming (OOP) using Classes and Structs
* **Data Structures:** Fixed-size array implementation with tracking pointers (`front`, `rear`)
* **Key Features:** Input validation, sorting algorithms, search mechanisms, and billing calculations

---

## 📂 System Features & Class Structure

The core functionality is encapsulated within the `Reservation` class, handling the following operations:

1. **Add Reservation (`AddReservation`):**
   * Collects customer details: Name, Day of reservation (1–31), Time (1–12), Number of people (max 10), and Contact Number (exactly 10 digits).
   * Generates a unique 4-digit random reservation number.
   * Automatically sorts reservations chronologically and checks for schedule conflicts.

2. **Search Reservation (`search`):**
   * Allows staff to look up booking details using the unique reservation number.

3. **Make Payment & Ordering (`makePayment`):**
   * Displays a restaurant menu with items and prices (Burgers, Pizza, Pasta, Salads, etc.).
   * Calculates the total bill based on quantities ordered and deducts the standard reservation fee (`150 SAR`).
   * Automatically updates the reservation status to `Completed`.

4. **Cancel Reservation (`cancelReservation`):**
   * Changes the status of active/confirmed reservations to `Cancelled`. Completed reservations cannot be cancelled.

5. **Daily Income Tracker (`dailyIncome`):**
   * Computes and displays the total earnings for a specific day based on completed orders.

6. **Daily Schedule Display (`displayAllReservationForDay`):**
   * Shows an hourly breakdown (Available / Not Available) for any given day in the month.

7. **Edit Reservation (`editReservation`):**
   * Allows modification of reservation details (Name, Day, Time, Number of people, Contact number) *only* if the reservation status is `Confirmed`.

---

## 🚀 Getting Started & Execution

1. **Prerequisites:**
   * Ensure you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).

2. **Compile the code:**
   ```bash
   g++ main.cpp -o rrs_system
