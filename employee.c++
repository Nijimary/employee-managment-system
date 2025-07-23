#include<iostream>
using namespace std;

class employee{
protected:
    int empid;
    char name[50];
    double salary;
public:
  employee(){ 
    empid =0;
    salary=0;
    name[50]='\0';
}
virtual void input() {
    cout<<"enter id :";
    cin>>empid;
    cout<<"enter the name:";
    cin>>name;
    cout<<"enter salary:";
    cin>>salary;
}
virtual void display(){
    cout<< "\n\tid:"<< empid<< "\tname:"<< name<< "\tsalary:"<< salary<<endl;
}
int getid(){
    return empid;
}
char getname(){
    return name[50];
}
virtual ~employee() {}
};

class manager: public employee{
    double bonus;
public:
   manager() {
    bonus=0.0;
   }    
   void input(){
    employee::input();
    cout<<"enter bonus:";
    cin>>bonus;
   }
   void display(){
    employee::display();
    cout<<"bonus:"<<bonus<<endl;
   }
};

void deleteid(employee*emp[],int& count,int empid) {
    int found=-1;
    for(int i=0;i<count;i++){
        if(emp[i]-> getid() ==empid){
            found = i;
            break;

        }
    }
    if(found!= -1){
        int i;
        for(int j=i;i<count-1;i++){
            emp[j]=emp[j+1];

        }
        emp[count -1]= NULL;
        count--;
        cout<<"employee deleted successfully.\n";
    }
    else{
        cout<<"ID NOT FOUND!!!.\n";
    }
}

int main(){
    const int max=10;
    employee* emp[max];
    int count=0;
    int choice;
   
    do{
        cout << "=======================================";
        cout << "\n-------Employee Management Menu--------\n";
        cout << "=======================================\n";
        cout << "1. Add Employee\n"; 
        cout << "2. Display Employee\n"; 
        cout << "3. Delete Employee\n"; 
        cout << "4. Exit\n";
        cout << "=======================================\n";
        cout <<"Enter your choice:";
        cin >> choice;
        
        if(choice == 1){
            if(count < max){
               int type;
               cout << "1. Regular employee\n2. Manager\nChoose type:";
               cin>>type;
               if (type==1)
                   emp[count]= new employee();
                else
                   emp[count]= new manager();
                emp[count]->input();
                count++;
                cout<<"Employee added.\n";
            }else{
                cout<<"MAXIMUM LIMIT REACHED.\n";

            }
        }else if(choice == 2) {
            if(count==0)
               cout<< "NO RECORDS TO DISPLAY.\n";
            else{
                cout<<"=================================";
                cout<<"\n--------Employee Records--------\n";
                cout<<"=================================";
                for (int j = 0; j < count; j++) {
                   emp[j]->display();
                }
            }
        }else if (choice == 3) {
           int empid;
           cout << "Enter ID to delete: ";
           cin >> empid;
           deleteid(emp, count, empid);
        }else if (choice == 4) {
            cout<<"Exiting...\n";
        }else {
           cout<<"Invalid choice.\n";
        }
    }while(choice !=4);
   
return 0;
}
