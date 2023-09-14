#include<iostream>
#include<ctime>
using namespace std;

//RANDOM NUMBER GENERATING FUNCTION
void numberGuessing(int choicesLeft)
{
    //GENERATING SECRET RANDOM NUMBER
    srand(time(0));
    int secretNumber = 1 + (rand()%100);
    int playerChoice;
    cout << "You have "<<choicesLeft<<" choices for finding the secret number between 1 and 100.\n";

    //GAME LOGIC
    while(choicesLeft != 0){
        //USER INPUT
        cout << "\nEnter the number: ";
        cin  >> playerChoice;

        if(playerChoice == secretNumber){
            cout << "Well played! You won, "<<secretNumber<<" is the secret number.\n\n";
            cout << "\t\t\t Thanks for playing....\n";
            break;
        }
        else if(secretNumber < playerChoice){
            cout<<"\nNope, " << playerChoice << " is not the right number.\n";
            cout << "The secret number is smaller than the number you have chosen.\n";
        }
        else{
            cout << "The secret number is greater than the number you have chosen.\n";
        }

        //DECREMENTING CHOICES LEFT AFTER EACH INPUT
        choicesLeft--;
        cout <<"\n"<< choicesLeft << " choices left\n";
        if (choicesLeft == 0) {
            cout << "\nYou couldn't find the secret number, it was "<< secretNumber << ", You lose!!\n";
            cout << "Play the game again to win!!!\n";
        }
    }
}

//MAIN FUNCTION
int main()
{
    char confirm;

    cout << "***************************************************************\n";
    cout << "\t\tWelcome to Number Guessing Game!!\n";
    cout << "***************************************************************\n\n";
    cout << ">> A random number will be generated between 1 and 100.\n>> You have to guess that number within the limited choices based";
    cout << " on the level of difficulty you choose.\n\nGood Luck!!\n\n";

    do{

        //LEVEL OF DIFFICULTY
        cout << "Difficulty level:\n";
        cout << "1 for easy - 10 choices!\t\t";
        cout << "2 for medium - 7 choices!\n";
        cout << "3 for difficult - 5 choices!\t\t";
        cout << "0 for ending the game!\n\n";

        //TAKING USER INPUT FOR DIFFICULTY CHOICE
        int difficultyLevel;
        cout << "Enter difficulty level: ";
        cin>>difficultyLevel;

        if(difficultyLevel == 1){
            numberGuessing(10);
        }
        else if(difficultyLevel == 2){
            numberGuessing(7);
        }
        else if(difficultyLevel == 3){
            numberGuessing(5);
        }
        else if(difficultyLevel == 0){
            return 0;
        }
        else{
            cout << "\nWrong choice, Enter valid choice to play the game! (0,1,2,3)\n";
        }

        //IF PLAYER WANT TO PLAY AGAIN
        cout<<"\nDo you want to continue?..(Y/y or N/n)\nConfirmation: ";
        cin>> confirm;
        cout<<"\n";
    }while( confirm == 'Y'|| confirm == 'y');

    cout<<"***********EXITING!!*********\n";
    cout<<"*************END*************\n\n";

    return 0;
}
