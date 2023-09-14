#include<iostream>
using namespace std;

int main()
{
    cout<<"*************SIMPLE CALCULATOR*************\n\n\n";

    ///DECLARATION OF VARIABLES
    double No1,No2;
    int choice;
    char confirm;

    ///WORKING OF CALCULATOR
    do{
        ///USER INPUT
        cout<<"Enter First Number: ";
        cin>>No1;
        cout<<"Enter Second Number: ";
        cin>>No2;
        cout<<"\nChoose one of the following option:\n\n";
        cout<<"1) ADDITION\n2) SUBRACTION\n3) MULTIPLICATION\n4) DIVISION\n5) If you want to EXIT, press 5: \n";
        cout<<"\nEnter Option: ";
        cin>>choice;
        cout<<"\n";

        ///MAIN LOGIC OF CALCULATOR
        switch(choice)
        {
            case 1: cout<<"ADDITION -> "<<"Answer is: "<<No1<<" + "<<No2<<" = "<<No1+No2<<"\n";break;
            case 2: cout<<"SUBRACTION -> "<<"Answer is: "<<No1<<" - "<<No2<<" = "<<No1-No2<<"\n";break;
            case 3: cout<<"MULTIPLICATION -> "<<"Answer is: "<<No1<<" * "<<No2<<" = "<<No1*No2<<"\n";break;
            case 4: cout<<"DIVISION -> "<<"Answer is: "<<No1<<" / "<<No2<<" = "<<No1/No2<<"\n";break;
            case 5:cout<<"*************EXITING!!*************\n\n"; return 0;
            default: cout<<"INVALID OPTION!!!\n\n*************EXITING!!*************\n\n"; return 0;
        }

        ///USING CALCULATOR AGAIN ( if press Y/y, calculator runs again, otherwise it will exit.)
        cout<<"\nDo you want to continue?..(Y/y or N/n)\nConfirmation: ";
        cin>> confirm;
        cout<<"\n";
    }while( confirm == 'Y'|| confirm == 'y');
    cout<<"***********EXITING!!*********\n\n";
    cout<<"*************END*************\n\n";

    return 0;
}
