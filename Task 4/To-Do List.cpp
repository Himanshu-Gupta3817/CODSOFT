#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<string>
using namespace std;

//GLOBAL DECLARATION OF MAP
map<string, string> todo;


//FUNCTION FOR DISPLAYING TO-DO LIST
void viewToDo()
{
    //NO ELEMENTS PRESENT IN LIST
    if(todo.empty()){
        cout<<"\nList is Empty!!\n";
    }
    //ELEMENTS PRESENT IN LIST
    else{
            int taskNumber = 1;
            cout<<"\nList:\n";
            //( it = todo.begin(); it != todo.end(); it++)
            for(auto it : todo){
                cout<<taskNumber++<<") "<<it.first<<" - "<<it.second<<"\n";
            }
    }
}

//FUNCTION TO ADD TASKS TO LIST
void addToDo()
{
    string task;
    cout<<"Enter Task: ";
    cin.ignore();
    getline(cin,task);
    todo.insert({task,"Pending"});
    cout<<"Task added successfully!!\n";
    viewToDo();
}

void updateToDo()
{
    //IF LIST IS EMPTY
    if(todo.empty()){
        cout<<"No Task to update!!\n";
    }
    //LIST IS NOT EMPTY
    else{
        int taskNumber = 0;
        map<string, string>:: iterator it;
        it = todo.begin();
        //USING ITERATOR TO LOCATE THE TASK
        cout<<"Enter the Task number to be updated: ";
        cin>>taskNumber;
        taskNumber-=1;
        while(taskNumber!=0){
            it++;
            --taskNumber;
        }
        it->second = "Completed";
        cout<<"Task updated successfully!!\n";
        viewToDo();
    }
}

void deleteToDo()
{
    //IF LIST IS EMPTY
    if(todo.empty()){
        cout<<"No Task to delete!!\n";
    }
    //LIST IS NOT EMPTY
    else{
        int taskNumber = 0;
        map<string, string>:: iterator it;
        it = todo.begin();
        //USING ITERATOR TO LOCATE THE TASK
        cout<<"Enter the Task number to be deleted: ";
        cin>>taskNumber;
        taskNumber-=1;
        while(taskNumber!=0){
            it++;
            --taskNumber;
        }
        todo.erase(it);
        cout<<"Task deleted successfully!!\n";
        viewToDo();
    }
}

void clearToDo()
{
    todo.clear();
    cout<<"List is Clear!!\n";
}

int main()
{
    int choice;
    char confirm;

    cout<<"***********************************************************\n";
    cout<<"\t\tWELCOME TO TO-DO LIST\n";
    cout<<"***********************************************************\n";

     do{
        cout<<"\n>> What do you want to do in the TO-DO List?\n\n";
        cout<<"1.Add New Task\n2.View all Tasks\n3.Update a Task\n4.Delete a Task\n5.Clear TO-DO List\n6.If you want to EXIT, press 6:\n";

        //USER INPUT
        cout<<"\n>> Enter Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: addToDo();break;
            case 2: viewToDo();break;
            case 3: updateToDo();break;
            case 4: deleteToDo();break;
            case 5: clearToDo();break;
            case 6:cout<<"\n***********EXITING!!*********\n*************END*************\n"; return 0;
            default: cout<<"\nINVALID OPTION!!\n";break;
        }
    }while(choice != 6);

    return 0;
}
