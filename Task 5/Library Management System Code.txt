#include<iostream>
#include<fstream>
#include<string>
using namespace std;


//Librarian Menu Password is librarian@23
//User Menu Password is user123

//GLOBAL DECLARATIONS AND FUNCTION PROTOTYPES

string oldPassword = "librarian@23";
void librarian();
void user();
void writeBook();
void writeUser();
void displayBook();
void displayUser();
void searchBook();
void addDeleteBook();
void addDeleteUser();
void bookIssue();
void bookDeposit();
void changePassword();
int administratorMenu();


///////////////////////////////////////////////////////////////////////////



///*****CLASSES USED IN PROJECT*****

//BOOK CLASS
class Book
{

public:
    string ISBN;
    string bookTitle;
    string authorName;
    int copiesAvailable;


    //Create function of book class
    void createBook()
    {
        cout << "\n\nNEW BOOK ENTRY...";
        cout << "\nEnter The book no.: ";
        cin.ignore();
        getline(cin,ISBN);
        cout << "Enter The Name of The Book: ";
        getline(cin,bookTitle);
        cout << "Enter The Author's Name: ";
        getline(cin,authorName);
        cout << "Enter the number of copies available: ";
        cin >> copiesAvailable;
        cout << endl;
        cout << "\nBook Created..\n";
    }


    //Display function of book class
    void showBook()
    {
        cout << "\nBook no.: " << ISBN;
        cout << "\nBook Name: " << bookTitle;
        cout << "\nAuthor Name: " << authorName;
        cout << "\nNumber of copies available: " << copiesAvailable;
    }


    //Other important functions of book class
    string returnBookNumber()
    {
        return ISBN;
    }

    string returnBookName()
    {
        return bookTitle;
    }

    string returnBookAuthor()
    {
        return authorName;
    }

    int returnCopiesAvailable()
    {
        return copiesAvailable;
    }

    void issueBook()
    {
        if (copiesAvailable > 0) {
            copiesAvailable--;
        }
        else {
            cout << "\nNo copies of this book available for issue.\n";
        }
    }

    void returnBook()
    {
        copiesAvailable++;
    }
};



//USER CLASS
class User
{
public:
    string userName;
    string userAddress;
    string userPnumber;
    int token;
    string userBookNumber;

    //Create function of user class
    void createUser()
    {
        cout << "\n\nNEW USER ENTRY...";
        cout << "\nEnter the User name: ";
        cin.ignore();
        getline(cin,userName);
        cout << "Enter User's Address: ";
        getline(cin,userAddress);
        cout << "Enter User's Phone number: ";
        getline(cin,userPnumber);
        token = 0;
        userBookNumber = "NA";
        cout << "\nUser Entry Successfully Created..\n";
    }


    //Display function of user class
    void showUser()
    {
        cout << "\nUser Name: " << userName;
        cout << "\nUser Address: " << userAddress;
        cout << "\nUser Phone number: " << userPnumber;
        cout << "\nNo of Book issued: " << token;
        cout << "\nBook no.: " << userBookNumber;

    }


    //Other important functions of user class
    string returnUserPhoneNumber()
    {
        return userPnumber;
    }

    string returnUserBookNumber()
    {
        return userBookNumber;
    }

    int returnUserToken()
    {
        return token;
    }

    void addtoken()
    {
        token = 1;
    }

    void resettoken()
    {
        token = 0;
    }

    void setUserBookNumber(string t)
    {
        userBookNumber = t;
    }
};

///*****CLASS ENDS*****




///USING FILE HANDLING

///////////////////////////////////////////////////////////////////////////



///GLOBAL DECLARATION OF OBJECTS OF CLASSES

fstream fileIO, file1, file2;
Book bk;
User us;



// DEFINING AN EXTRACTION OPERATOR FOR THE BOOK CLASS, i.e, READING A FILE
istream& operator>>(istream& is, Book& bk)
{
    is >> bk.ISBN >> ws; // ws is a manipulator that discards whitespace
    getline(is, bk.bookTitle);
    getline(is, bk.authorName);
    is >> bk.copiesAvailable;
    cout << endl;
    return is;
}

// DEFINING AN EXTRACTION OPERATOR FOR THE USER CLASS, i.e, READING A FILE
istream& operator>>(istream& is, User& us)
{
    //is >> ws; // ws is a manipulator that discards whitespace
    getline(is, us.userName);
    getline(is, us.userAddress);
    getline(is, us.userPnumber);
    is >> us.token >> ws;
    getline(is, us.userBookNumber);
    cout << endl;
    return is;
}


//*******************************************************************************************************************************


// DEFINING AN INSERTION OPERATOR FOR THE BOOK CLASS, i.e, WRITING IN A FILE
ostream& operator<<(ostream& os, const Book& bk)
{
    os << bk.ISBN << "\n" << bk.bookTitle << "\n" << bk.authorName << "\n" << bk.copiesAvailable << endl;
    return os;
}


// DEFINING AN INSERTION OPERATOR FOR THE USER CLASS, i.e, WRITING IN A FILE
ostream& operator<<(ostream& os, const User& us)
{
    os << us.userName << endl << us.userAddress << endl << us.userPnumber << endl << us.token << endl << us.userBookNumber << endl;
    return os;
}




///////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////


//FUNCTION TO WRITE BOOK RECORD IN FILE
void writeBook()
{
    char confirm;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt", ios::out | ios::app);

    do{
        bk.createBook();
        fileIO << bk;
        cout << "Do you want to add more records?...(y/n): ";
        cin >> confirm;
    }while(confirm == 'Y' || confirm == 'y');

    fileIO.close();
}



//FUNCTION TO WRITE USER RECORD IN FILE
void writeUser()
{
    char confirm;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt", ios::out | ios::app);

    do{
        us.createUser();
        fileIO << us;
        cout << "Do you want to add more Users?...(y/n): ";
        cin >> confirm;
    }while(confirm == 'Y' || confirm == 'y');

    fileIO.close();
}


///////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////


//FUNCTION TO DISPLAY ALL BOOK RECORD FROM FILE
void displayBook()
{
    bool flag = false;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt", ios::in);

    if(!fileIO){
        cout << "Error!! File could not be open\n";
        return;
    }
    else{
        cout << "BOOK LIST: ";
        while(fileIO >> bk){
            bk.showBook();
            flag = true;
        }
        fileIO.close();
        if(!flag)
            cout << ">> Book List is Empty!!\n";
    }

    administratorMenu();
}


//FUNCTION TO DISPLAY ALL USER RECORD FROM FILE
void displayUser()
{
    bool flag = false;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt", ios::in);

    if(!fileIO){
        cout << "Error!! File could not be open\n";
        return;
    }
    else{
        cout << "USER LIST:\n";
        while(fileIO >> us){
            us.showUser();
            flag = true;
        }
        fileIO.close();
        if(!flag)
            cout << ">> User List is Empty!!\n";
    }

    administratorMenu();
}
///////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////////

//FUNCTION TO SEARCH BOOK RECORD FROM FILE
void searchBook()
{
    int choice, counter = 0;
    string isbn,title,author;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt",ios::in);

    int currentPos = fileIO.tellg();    // Get the current position of the file stream
    fileIO.seekg(0, ios::end);          // Move the file stream to the end of the file
    int endPos = fileIO.tellg();        // Get the end position of the file stream
    fileIO.seekg(currentPos);           // Move the file stream back to the original position
    if(currentPos == endPos) {          // Compare the current and end positions
        // The file is empty
        cout << "The File is Empty!!\n";
    }
    else{
        cout << "\nSearch Book By:\n1.ISBN     2.Title       3.Author\n\n";
        cout << "Enter choice: ";
        cin >> choice;
        if(fileIO.is_open()){

            switch(choice)
            {
                case 1: // SEARCH BY ISBN
                        cout << "Enter Book ISBN: ";
                        cin.ignore();
                        getline(cin,isbn);
                        while(fileIO >> bk){
                            if(bk.returnBookNumber() == isbn){
                                bk.showBook();
                                counter++;
                            }
                        }
                        if(counter > 0){
                            cout << "\nBook Found!!\n";
                        }
                        else{
                            cout << "No Record Found!!\n";
                        }
                        break;

                case 2: // SEARCH BY TITLE
                        cout << "Enter Book Title: ";
                        cin.ignore();
                        getline(cin,title);
                        while(fileIO >> bk){
                            if(bk.returnBookName() == title){
                                bk.showBook();
                                counter++;
                            }
                        }
                        if(counter > 0){
                            cout << "\nBook Found!!\n";
                        }
                        else{
                            cout << "No Record Found!!\n";
                        }
                        break;

                case 3: // SEARCH BY AUTHOR
                        cout << "Enter Book Author: ";
                        cin.ignore();
                        getline(cin,author);
                        while(fileIO >> bk){
                            if(bk.returnBookAuthor() == author){
                                bk.showBook();
                                counter++;
                            }
                        }
                        if(counter > 0){
                            cout << "\nBook Found!!\n";
                        }
                        else{
                            cout << "No Record Found!!\n";
                        }
                        break;

                default: cout << "Invalid Choice!!"; return;
            }
            fileIO.close();
        }
        else{
            cout << "Error!! File not found\n";
        }
    }

    administratorMenu();
}

///////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////


//FUNCTION TO DELETE BOOK FROM FILE
void deleteBook()
{
    string number;
    char confirm;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt", ios::in);
    file2.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Temp.txt", ios::out);

    fileIO.seekg(0,ios::beg);
    // Check if both files are open

        if(fileIO.is_open() && file2.is_open()) {

            int currentPos = fileIO.tellg();    // Get the current position of the file stream
            fileIO.seekg(0, ios::end);          // Move the file stream to the end of the file
            int endPos = fileIO.tellg();        // Get the end position of the file stream
            fileIO.seekg(currentPos);           // Move the file stream back to the original position
            if(currentPos == endPos) {          // Compare the current and end positions

                // The file is empty
                cout << "\nThe File is Empty!!\n";
            }
            else{
                do{
                    cout << "\nEnter the Book number you want to delete: ";
                    cin.ignore();
                    getline(cin,number);

                    // Loop through the original file until end of file is reached
                    while(fileIO >> bk){

                        if(bk.returnBookNumber() != number)
                        {
                            file2 << bk;
                        }
                    }

                    cout<<"Record Deleted ..\n";
                    cout << "\nDo you want to delete more record?...(y/n): ";
                    cin >> confirm;

                }while(confirm == 'Y' || confirm == 'y');
            }

            // Above we are copying the contents of those books which are not deleted by the librarian in the Temp.txt file.
            // And removing Book.txt file and renaming the Temp.txt file to Book.txt file.
            fileIO.close();
            file2.close();
            remove("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt");
            rename("C:\\Users\\Dell\\Desktop\\Codsoft\\Temp.txt","C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt");

        }
        else{
            cout << "Error!! File could not be open\n";
        }

        administratorMenu();
}


//FUNCTION TO DELETE USER FROM FILE
void deleteUser()
{
    string number;
    char confirm;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt", ios::in);
    file2.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Temp.txt", ios::out);

    fileIO.seekg(0,ios::beg);
    // Check if both files are open

        if(fileIO.is_open() && file2.is_open()) {

            int currentPos = fileIO.tellg();    // Get the current position of the file stream
            fileIO.seekg(0, ios::end);          // Move the file stream to the end of the file
            int endPos = fileIO.tellg();        // Get the end position of the file stream
            fileIO.seekg(currentPos);           // Move the file stream back to the original position
            if(currentPos == endPos) {          // Compare the current and end positions

                // The file is empty
                cout << "\nThe File is Empty!!\n";
            }
            else{
                do{
                    cout << "\nEnter the User Phone number you want to delete: ";
                    cin.ignore();
                    getline(cin,number);

                    // Loop through the original file until end of file is reached
                    while(fileIO >> us){

                        if(us.returnUserPhoneNumber() != number)
                        {
                            file2 << us;
                        }
                    }

                    cout<<"Record Deleted ..\n";
                    cout << "\nDo you want to delete more records?...(y/n): ";
                    cin >> confirm;

                }while(confirm == 'Y' || confirm == 'y');
            }

            // Above we are copying the contents of those users which are not deleted by the librarian in the Temp.txt file.
            // And removing User.txt file and renaming the Temp.txt file to User.txt file.
            fileIO.close();
            file2.close();
            remove("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt");
            rename("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Temp.txt","C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt");

        }
        else{
            cout << "Error!! File could not be open\n";
        }

        administratorMenu();
}
///////////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////////////////////////////

//FUNCTION TO ISSUE BOOK
void bookIssue()
{
    string userPhoneNumber, bookNumber;
    char confirm;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt", ios::in | ios::out);

    int currentPos = fileIO.tellg();        // Get the current position of the file stream
    fileIO.seekg(0, ios::end);              // Move the file stream to the end of the file
    int endPos = fileIO.tellg();            // Get the end position of the file stream
    fileIO.seekg(currentPos);               // Move the file stream back to the original position
    if(currentPos == endPos) {              // Compare the current and end positions

        // The file is empty
        cout << "The File is Empty!!\n";
        cout << "\nDo you want to create User record?...(y/n): ";
        cin >> confirm;

        if(confirm == 'Y' || confirm == 'y'){

            // Writing user record in file
            fileIO.close();
            writeUser();
            us.showUser();
            fileIO.close();

            cout << endl;
            return;
        }
        else{
            fileIO.close();
            return;
        }
    }

    fileIO.close();
    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt", ios::in | ios::out);
    file1.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt", ios::in | ios::out);
    fstream fileUserIssue ("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\UserIssue.txt", ios::in | ios::out | ios::app);
    fstream fileBookIssue ("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\BookIssue.txt", ios::in | ios::out | ios::app);

    fileIO.clear(); // Clear any error flags
    fileIO.seekg(0); // Rewind the user file to the beginning
    file1.clear(); // Clear any error flags
    file1.seekg(0); // Rewind the book file to the beginning


    // Checking if file open correctly or not
    if(fileIO.is_open() && file1.is_open() && fileBookIssue.is_open() && fileUserIssue.is_open()){

        cout<<"\n\nBOOK ISSUE ...\n\n";
        cout<<"\nEnter The User's Phone no.: ";
        cin.ignore();
        cin >> userPhoneNumber;

        bool foundUser = false;

        while(fileIO >> us){
            if( us.returnUserPhoneNumber() != userPhoneNumber ){
                fileUserIssue << us;
            }
            else{
                foundUser = true;

                if( us.returnUserToken() == 0){

                    cout << "Enter the Book Number: ";
                    cin.ignore();
                    getline(cin,bookNumber);

                    bool foundBook = false;

                    while( file1 >> bk){
                        if( bk.returnBookNumber() != bookNumber){
                                fileBookIssue << bk;
                        }
                        else{
                            if(bk.returnCopiesAvailable() > 0){

                                bk.issueBook();
                                fileBookIssue << bk;
                                bk.showBook();

                                foundBook = true;
                                cout << endl;

                                us.addtoken();
                                us.setUserBookNumber(bk.returnBookNumber());
                                fileUserIssue << us;
                                us.showUser();

                                cout<<"\n\nBook Issued Successfully!!\nPlease Note: Write current date "
                                    << "in backside of book and submit within 15 days\nelse fine of "
                                    << "Rs. 1 for each day after 15 days period";
                            }
                            else{

                                foundBook = true;
                                cout << "\nNo copies of this book available for issue.\n";

                            }
                        }
                    }

                    // Above we are copying the contents of those books which are not demanded by user in the BookIssue.txt file.
                    // After that we are issuing the desired book to the user and then appending it to the BookIssue.txt file
                    // And removing old Book.txt file and we are renaming the BookIssue.txt file to Book.txt file.
                    fileBookIssue.close();
                    file1.close();
                    remove("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt");
                    rename("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\BookIssue.txt","C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt");

                    if( !foundBook ){
                        cout << "\nBook number does not exist.";
                    }
                }
                else{
                    cout << "\nYou have not returned the last book.";
                }
            }
        }

        //  Above we are copying the contents of those users which are not issuing the book in the UserIssue.txt file.
        // After that we are issuing the desired book to the user and then appending it to the UserIssue.txt file
        // And removing old User.txt file and we are renaming the UserIssue.txt file to User.txt file.
        fileUserIssue.close();
        fileIO.close();
        remove("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt");
        rename("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\UserIssue.txt","C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt");

        if(!foundUser){
            cout << "User record does not exist...";
            cout << "\nDo you want to create User record?...(y/n): ";
            cin >> confirm;

            if(confirm == 'Y' || confirm == 'y'){
                fileIO.close();
                writeUser();
                us.showUser();
                fileIO.close();
                cout << endl;
                return;
            }
            else{
                return;
            }
        }

        fileIO.close();
        file1.close();

    }
    else{
        cout << "Error!! File could not be open\n";
        return;
    }

    administratorMenu();
}


//////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////

//FUNCTION TO DEPOSIT BOOK
void bookDeposit()
{
    string userPhoneNumber;
    int day, fine;

    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt", ios::in | ios::out);

    int currentPos = fileIO.tellg();        // Get the current position of the file stream
    fileIO.seekg(0, ios::end);              // Move the file stream to the end of the file
    int endPos = fileIO.tellg();            // Get the end position of the file stream
    fileIO.seekg(currentPos);               // Move the file stream back to the original position
    if(currentPos == endPos) {              // Compare the current and end positions

        // The file is empty
        cout << "The File is Empty!!\n";
        cout << "\nNothing to Deposit!!\n";
        return;
    }

    fileIO.close();
    fileIO.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt", ios::in | ios::out);
    file1.open("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt", ios::in | ios::out);
    fstream fileUserDeposit ("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\UserDeposit.txt", ios::in | ios::out | ios::app);
    fstream fileBookDeposit ("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\BookDeposit.txt", ios::in | ios::out | ios::app);

    fileIO.clear(); // Clear any error flags
    fileIO.seekg(0); // Rewind the user file to the beginning
    file1.clear(); // Clear any error flags
    file1.seekg(0); // Rewind the book file to the beginning


    // Checking if file open correctly or not
    if(fileIO.is_open() && file1.is_open() && fileBookDeposit.is_open() && fileUserDeposit.is_open()){

        cout<<"\n\nBOOK DEPOSIT ...\n\n";
        cout<<"\nEnter The User's Phone no.: ";
        cin.ignore();
        cin >> userPhoneNumber;

        bool foundUser = false;

        while(fileIO >> us){
            if( us.returnUserPhoneNumber() != userPhoneNumber ){
                fileUserDeposit << us;
            }
            else{
                foundUser = true;

                if( us.returnUserToken() == 1){

                    bool foundBook = false;

                    while( file1 >> bk){
                        if( us.returnUserBookNumber() != bk.returnBookNumber()){
                                fileBookDeposit << bk;
                        }
                        else{

                                bk.returnBook();
                                fileBookDeposit << bk;
                                //bk.showBook();

                                foundBook = true;
                                cout << endl;

                                us.resettoken();
                                us.setUserBookNumber("NA");
                                fileUserDeposit << us;
                                //us.showUser();

                                //FINE CALCULATION
                                cout << "\n\nBook deposited in number of days: ";
                                cin >> day;
                                if(day > 15){
                                    fine = (day - 15) * 10;
                                    cout<<"\nFine has to deposited Rs. "<< fine;
                                }


                                cout<<"\n\nBook Deposited Successfully.\n";

                        }
                    }

                    // Above we are copying the contents of those books which are not demanded by user in the BookIssue.txt file.
                    // After that we are issuing the desired book to the user and then appending it to the BookIssue.txt file
                    // And removing old Book.txt file and we are renaming the BookIssue.txt file to Book.txt file.
                    fileBookDeposit.close();
                    file1.close();
                    remove("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt");
                    rename("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\BookDeposit.txt","C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\Book.txt");

                    if( !foundBook ){
                        cout << "\nNo Book has been issued.";
                    }
                }
                else{
                    cout << "\nYou have not issued any book.";
                }
            }
        }

        //  Above we are copying the contents of those users which are not issuing the book in the UserIssue.txt file.
        // After that we are issuing the desired book to the user and then appending it to the UserIssue.txt file
        // And removing old User.txt file and we are renaming the UserIssue.txt file to User.txt file.
        fileUserDeposit.close();
        fileIO.close();
        remove("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt");
        rename("C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\UserDeposit.txt","C:\\Users\\Dell\\Desktop\\Codsoft\\Task 5\\User.txt");

        if(!foundUser){
            cout << "User record does not exist...";
            cout << "\nCan't Deposit the Book.\n";

        }

        fileIO.close();
        file1.close();

    }
    else{
        cout << "Error!! File could not be open\n";
        return;
    }

    administratorMenu();
}
///////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////

//FUNCTION TO UPDATE BOOK LIST
void addDeleteBook()
{
    cout << "\nUPDATE BOOKLIST....\n";
    cout << "1.Add Book\n2.Delete Book\n";
    int choice;
    cout << "\nEnter choice: ";
    cin >> choice;
    switch(choice)
    {
        case 1: cout << "ADDING BOOK....";
                writeBook();
                break;
        case 2: cout << "DELETING BOOK....\n";
                deleteBook();
                break;
        default: cout << "Invalid Choice!!"; return;
    }

    administratorMenu();
}



//FUNCTION TO UPDATE USER LIST
void addDeleteUser()
{
    cout << "\nUPDATE USERLIST....\n";
    cout << "1.Add User\n2.Delete User\n";
    int choice;
    cout << "\nEnter choice: ";
    cin >> choice;
    switch(choice)
    {
        case 1: cout << "ADDING USER....";
                writeUser();
                break;
        case 2: cout << "DELETING USER....\n";
                deleteUser();
                break;
        default: cout << "Invalid Choice!!"; return;
    }

    administratorMenu();
}
///////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////

//FUNCTION TO CHANGE PASSWORD
void changePassword()
{
    string newPassword, password;
    cout << "Enter Old Password: ";
    cin.ignore();
    getline(cin,password);

    if(password == oldPassword){
        cout << "Enter New Password: ";
        getline(cin,newPassword);
        ::oldPassword = newPassword;
        cout << "Password Change Successfully!!\n\n";
        librarian();
    }
    else{
        cout << "Wrong Password!!\n\n"; return;
    }

    administratorMenu();
}
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////

int administratorMenu()
{
        cout << "\n****************** WELCOME LIBRARIAN ******************\n";
        cout << "-------------------------------------------------------\n\n";
        cout << ">> Please Choose Option:\n\n";
        cout << "1. View BookList\n2. View UserList\n3. Search for a Book\n4. Update Book\n5. Update User\n6. Issue Book\n7. Return Book\n8. Change Password\n9. Close Application\n\n";

        int choice;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: displayBook(); break;
            case 2: displayUser(); break;
            case 3: searchBook(); break;
            case 4: addDeleteBook(); break;
            case 5: addDeleteUser(); break;
            case 6: bookIssue(); break;
            case 7: bookDeposit() ; break;
            case 8: changePassword(); break;
            case 9: cout << "\n***********EXITING!!*********\n*************END*************\n"; break;
            default: cout << "\nINVALID OPTION!!\n"; break;
        }

        return 0;
}


///////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////

//MENU FUNCTION FOR USER
void user()
{
    string password;
    cout << "Enter Password: ";
    cin.ignore();
    getline(cin,password);

    if( password == "user123"){
        cout << "\n|| LOGGED IN: ||\n";
        cout << "\n******************** WELCOME USER ********************\n";
        cout << "-------------------------------------------------------\n\n";
        cout << ">> Please Choose Option:\n\n";
        cout << "1. View BookList\n2. Search for a Book\n3. Close Application\n\n";

        int choice;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: displayBook(); break;
            case 2: searchBook(); break;
            case 3: cout << "\n***********EXITING!!*********\n*************END*************\n"; return;
            default: cout << "\nINVALID OPTION!!\n"; break;
        }
    }
    else{
        cout << "\nWrong Password!!\n\n"; return;
    }
}


//MENU FUNCTION FOR LIBRARIAN
void librarian()
{
    string password;
    cout << "Enter Password: ";
    cin.ignore();
    getline(cin,password);

    if( password == oldPassword){
        cout << "\n|| LOGGED IN: ||\n";
        administratorMenu();
    }
    else{
        cout << "\nWrong Password!!\n\n"; return;
    }
}

///////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////

//MAIN FUNCTION
int main()
{
    cout << "************** LIBRARY MANAGEMENT SYSTEM **************\n";
    cout << "-------------------------------------------------------\n\n";
    cout << ">> Please Choose Option To Login:\n\n";
    cout << "1. User\n2. Librarian\n3. Close Application\n\n";

    int choice;
    cout << "Enter Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1: user(); break;
        case 2: librarian(); break;
        case 3: cout << "\n***********EXITING!!*********\n*************END*************\n"; return 0;
        default: cout << "\nINVALID OPTION!!\n"; break;
    }

    return 0;
}

///////////////////////PROJECT ENDS////////////////////////////////////////
