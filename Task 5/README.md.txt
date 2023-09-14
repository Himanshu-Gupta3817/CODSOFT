# Library Management System

![Library Management System](Library Management System 1.png)
![Library Management System](Library Management System 2.png)
![Library Management System](Library Management System 3.png)
![Library Management System](Library Management System 4.png)
![Library Management System](Library Management System 5.png)
![Library Management System](Library Management System 6.png)
![Library Management System](Library Management System 7.png)
![Library Management System](Library Management System 8.png)
![Library Management System](Library Management System 9.png)

## Overview

The Library Management System (LMS) is a C++ program designed to facilitate efficient book and borrower management within a library. This system offers essential features for librarians, including book database management, book search, book checkout, book return, fine calculation for overdue books, and a user-friendly interface. 

## Key Components

1. **Book Class**: Represents book information, including title, author, ISBN, and available copies. It provides methods for creating, displaying, and managing book data.

2. **User Class**: Manages user details, such as name, address, phone number, borrowing status, and borrowed book information. It offers methods for user data management.

3. **File Handling**: Utilizes file input/output for persistent storage of book and user data in separate text files.

4. **Main Menu**: The `main()` function offers a menu-based interface, allowing users to choose between librarian and user roles. Users must enter correct passwords for access.

5. **Librarian Menu**: Librarians can view book and user lists, search for books, update book/user records, issue books, return books, and change passwords.

6. **User Menu**: Users can view the book list, search for books, and exit the application.

## Getting Started

### Logging In

1. Run the program and select either **User** or **Librarian**.

2. For **User** access, enter the default password: `user123`.

3. For **Librarian** access, use the default password: `librarian@23`.

### Librarian Menu

If logged in as a **Librarian**, you can:

- View the book list.
- View the user list.
- Search for books.
- Update book records.
- Update user records.
- Issue books.
- Return books.
- Change the password.

### User Menu

If logged in as a **User**, you can:

- View the book list.
- Search for books.
- Close the application.

### Passwords

- Librarian password: `librarian@23`.
- User password: `user123`.

Before running the program, ensure you have a C++ development environment set up. Adjust file paths and passwords as needed.

Feel free to customize this Library Management System code to meet your specific requirements.

## Contributors

- Himanshu Gupta
