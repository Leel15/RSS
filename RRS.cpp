#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std ;

const int reservation_fee = 150 ;
const int MAX = 372 ; // number of days in month (31) * number of times in day 

struct customer_info{
  string name ;
  int dayOfReservation; 
  int timeOfReservation; 
  int numberOfPeople ;
  string contactNumber ;
  string statusOfReservation ; 
  int numberOfReservation ; 
  int bill ; 
  int reservationCounter ; 
    
};

class Reservation{
  
  private : 
  customer_info numOfReservation[MAX] ;
  int front , rear ; 
    
  public :
  Reservation();
  void AddReservation();
  void search(int numR);
  void makePayment(int numR);
  void cancelReservation(int numR);
  void dailyIncome();
  bool check(int dayR, int timeR); 
  void displayAllReservationForDay();
  void editReservation();
  void sortReservations();
  
};
Reservation:: Reservation(){
    rear = front = -1; 
}

 void Reservation:: AddReservation(){ 
    if(rear == MAX-1){
        cout<<"Reservation is full" <<endl; 
        return ; 
    }
    rear++ ;
    
    if(front == -1)
    front =  0;
    
    cout<<"\n----- To Reservation for the current Month, Enter information -----  "<<endl;
    cout<<" Name : "; 
       cin>>numOfReservation[rear].name ; 
      
    cout<<" Day of reservation : "; 
    cin>>numOfReservation[rear].dayOfReservation ; 
    
    do{   // Verifies that the user entered the correct day
    if(numOfReservation[rear].dayOfReservation > 31||numOfReservation[rear].dayOfReservation <1){
        cout<<"Invalid day , try Again "<<endl; 
        cout<<" Day of reservation : "; 
        cin>>numOfReservation[rear].dayOfReservation ; 
    }
    }while(numOfReservation[rear].dayOfReservation > 31||numOfReservation[rear].dayOfReservation <1);
    
    
    cout<<"\n Avaliable Times  "<<endl; 
    cout<<endl; 
    cout<<" 1- 1:00 pm\t2- 2:00 pm \t3- 3:00 pm\t4- 4:00 pm  "<<endl; 
    cout<<" 5- 5:00 pm\t6- 6:00 pm \t7- 7:00 pm\t8- 8:00 pm  "<<endl; 
    cout<<" 9- 9:00 pm\t10- 10:00 pm \t11- 11:00 pm\t12- 12:00 am  "<<endl; 
    cout<<"\n Time of reservation :  "; 
    cin>>numOfReservation[rear].timeOfReservation ; 
    
   do{   // Verifies that the user entered the correct time
    if(numOfReservation[rear].timeOfReservation > 12){
        cout<<"Invalid time , try Again "<<endl; 
    cout<<" Time of reservation :  "; 
        cin>>numOfReservation[rear].timeOfReservation ; 
    }
    }while(numOfReservation[rear].timeOfReservation > 12);
    
    //check if day and time reserved or no 
    if(check(numOfReservation[rear].dayOfReservation, numOfReservation[rear].timeOfReservation)){
        cout << "\n*** This day and time is already reserved ***" << endl; 
        cout << "\tPlease choose another time or day" << endl; 
        cout<<endl; 
        rear-- ; 
        return;
    }
    else{
        
    cout<<" Number of people :  "; 
    cin>>numOfReservation[rear].numberOfPeople;
    
    do{   // The Max number Of People in each table is 10 
    if(numOfReservation[rear].numberOfPeople > 10){
        cout<<" The number of people is not enough for the table , Enter a number of people not exceeding 10 "<<endl; 
    cout<<" Number of people :  "; 
        cin>>numOfReservation[rear].numberOfPeople ; 
    }
    }while(numOfReservation[rear].numberOfPeople > 10);
    
     
    cout<<" Contact Number :  "; 
    cin>>numOfReservation[rear].contactNumber; 
    do{  // Verifies that the user entered the correct Contact Number , Contact Number exactly contain 10 numbers 
    if(numOfReservation[rear].contactNumber.length() != 10){
        cout<<"Invalid Contact Number , try Again "<<endl; 
    cout<<"  Contact Number :  "; 
        cin>>numOfReservation[rear].contactNumber ; 
    }
    }while(numOfReservation[rear].contactNumber.length() != 10);
    

   numOfReservation[rear].statusOfReservation = "Confirmed";
   numOfReservation[rear].numberOfReservation = rand()%9000 + 1000; // Generate a reservation number containing 4 digits
   
    cout<<"\n\tReservation added successfully !"<<endl; 
    cout<<"\t  Number of Reservation : #"<<numOfReservation[rear].numberOfReservation<<endl; 
    cout<<endl ;}
    sortReservations(); 

}
void Reservation::sortReservations() { 
    for (int i = 0; i <= rear; ++i) {
        for (int j = 0; j < rear - i; ++j) {
            if (numOfReservation[j].dayOfReservation > numOfReservation[j + 1].dayOfReservation ||
               (numOfReservation[j].dayOfReservation == numOfReservation[j + 1].dayOfReservation &&
                numOfReservation[j].timeOfReservation > numOfReservation[j + 1].timeOfReservation)) {
                // Swap the reservations
                customer_info temp = numOfReservation[j];
                numOfReservation[j] = numOfReservation[j + 1];
                numOfReservation[j + 1] = temp;
            }
        }
    }

    // Assign unique reservation numbers starting from #1
    int reservationCount = 1;
    for (int i = 0; i <= rear; ++i) {
        numOfReservation[i].reservationCounter = reservationCount++;
    }
}

void Reservation::search(int numR){  
bool found = false;
    for (int i = 0; i <= rear; ++i) {
        if (numOfReservation[i].numberOfReservation == numR) {
        
            cout << "\n\t-----Reservation found for #" << numR << " -----" << endl;
             cout << "\n\t  Reservation in " <<  numOfReservation[i].name<<" name" <<endl;
            cout << "\n\t  Day of reservation: " << numOfReservation[i].dayOfReservation << endl;
            cout << "\n\t  Time of reservation: " << numOfReservation[i].timeOfReservation <<":00"<< endl;
            cout << "\n\t  Number of people: " <<numOfReservation[i].numberOfPeople<< endl;
            cout << "\n\t  Contact Number: " << numOfReservation[i].contactNumber<< endl;
            cout << "\n\t  Status of Reservation: " <<numOfReservation[i].statusOfReservation<< endl;
            cout << "\n\t-----------------------------------------" << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n\t  No Reservation number #" << numR << endl;
    }
    cout<<endl;


}
void Reservation:: makePayment (int numR){ 
    int Quantity; 
    int choice = 0;
    bool found = false;

    for(int i = 0 ; i<=rear ; i++){
        if( numOfReservation[i].numberOfReservation == numR){
    
           numOfReservation[i].bill=0;
           cout<<endl; 
    cout<<"\tRestaurant menu"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"1.chicken Burger    50 SAR"<<endl;
    cout<<"2.Beef Burger       55 SAR"<<endl;
    cout<<"3.pizza             75 SAR"<<endl;
    cout<<"4.Pasta             80 SAR"<<endl;
    cout<<"5.Cesar salad       55 SAR"<<endl;
    cout<<"6.Dynamite fries    45 SAR"<<endl;
        cout<<"\n"<<endl; 
    cout<<"Enter -1 If you want to finish your order"<<endl;
    cout<<endl; 
    
        while(choice !=-1){
        cout<<"Enter your choice : ";
        cin>>choice;
      
           if(choice>=1 && choice<=6){
               cout<<"Quantity : "; 
               cin>>Quantity;
               
               switch(choice){
                   case 1:
                   numOfReservation[i].bill+=50*Quantity;
                   break;
                   case 2:
                   numOfReservation[i].bill+=55*Quantity;
                   break;
                   case 3:
                   numOfReservation[i].bill+=75*Quantity;
                   break;
                   case 4:
                   numOfReservation[i].bill+=80*Quantity;
                   break;
                   case 5:
                   numOfReservation[i].bill+=55*Quantity;
                   break;
                   case 6:
                   numOfReservation[i].bill+=45*Quantity;
                   break;
               }
               cout<<endl; 
           }
           
           else if (choice !=-1){
               cout<<" Invalid choice, please try again"<<endl;}}
           
           cout<<endl; 
           numOfReservation[i].bill-= reservation_fee;
           numOfReservation[i].statusOfReservation="Completed";//update Reservation status to Completed
           cout<<"Your bill is "<<numOfReservation[i].bill<<" SAR\n"<<endl;
            found = true;
            break;}}
    
    
    if(!found) 
    cout << "\n\t  No Reservation number #" << numR << endl;
    cout<<endl;
}
    

void Reservation:: cancelReservation(int numR){  
    if(front==-1){
        cout<<"\n\t  No Reservations found\n"<<endl;
        return;
    }
   bool found = false;
    int i ; 
    for (i = 0; i <= rear; ++i) {
        if (numOfReservation[i].numberOfReservation == numR ) {
            if( numOfReservation[i].statusOfReservation != "Completed"){
            numOfReservation[i].statusOfReservation = "Cancelled";
            cout << "\n\t  Reservation #" << numR << " has been cancelled \n" << endl;
           found = true;
            break;
        }
        else 
            cout << "\n\t Reservation cannot be canceled " << ".\n" << endl;
            found = true;

        }
        
    }

    if (!found) {
        cout << "\n\t Invalid reservation number #" << numR  << endl;
    }

}


void Reservation::dailyIncome() // this function calculate the income of a chosen day , and show the whole payments of that day
{                           
    int IncomeOfDay = 0, Day;

    cout << "\n-----Daily Income-----\n"<< endl;
    cout << "Enter number for Day: ";
    cin >> Day; // choose day to calculate the income of its
    cout << "\n----------------------\n"<< endl;
    cout << "Reservation Number: \t income:\n\n";
    for (int i = 0; i <= rear; ++i)
    {
        if (numOfReservation[i].statusOfReservation == "Completed" && numOfReservation[i].dayOfReservation == Day) // To find payments that are Completed and match with the chosen day
        {                                                                                                        
            IncomeOfDay += numOfReservation[i].bill;
            cout << "#" << numOfReservation[i].numberOfReservation << "                   \t " << numOfReservation[i].bill << " SAR" << endl;
        }
    }

    if (IncomeOfDay == 0) // if there is no reservation for the choosen day
    {
        cout << "\n\t  No reservations for day " << Day << endl;
        cout<<endl;
        return;
    }
    else
        cout << "\nDay income = " << IncomeOfDay << " SAR " << endl;

    cout << "\n----------------------\n"<< endl;
}

bool Reservation::check(int dayR, int timeR){ 

    for(int i = 0; i < rear; i++){
        if(numOfReservation[i].dayOfReservation == dayR && numOfReservation[i].timeOfReservation == timeR){
            if(numOfReservation[i].statusOfReservation == "Confirmed" || numOfReservation[i].statusOfReservation == "Completed")// if statusOfReservation = cancelled you can reserved in the same date and time 
                return true ; 
        }
    }
    return false; //  is not reserved and "available"
}        

void Reservation::displayAllReservationForDay(){
    int day; 
    cout << "\nReservation status for day :  "; 
    cin>> day ;
    cout << "\nTime\t\tStatus Of Reservation" << endl;
    cout << "-----------------------------------------" << endl;
     int timeR; 
    for( timeR = 1; timeR <= 12; timeR++){ 
        bool reserved = false;
        for(int i = 0; i <= rear; i++){
            if(numOfReservation[i].dayOfReservation == day && numOfReservation[i].timeOfReservation == timeR){
                if(numOfReservation[i].statusOfReservation != "Cancelled"){
                if(timeR >= 10 ){ // this step not important , just to have a good output format
                    if(timeR == 12) // 12 is excepet because it is "am" instead of "pm"
                        cout << timeR << ":00 am\tNot Available" << endl;
                    else 
                        cout << timeR << ":00 pm\tNot Available" << endl;}
                else 
                 cout << timeR << ":00 pm\t\tNot Available" << endl;
                
                reserved = true;
                break;  // Found reservation for this time, so move to the next time 
            }}
        }
        if(!reserved){
           if(timeR >= 10 ){  // this step not important , just to have a good output format
                if(timeR == 12) //12 is excepet because it is "am" instead of "pm"
                    cout << timeR << ":00 am\tAvailable" << endl;
                else 
                     cout << timeR << ":00 pm\tAvailable" << endl;}
            else 
                cout << timeR << ":00 pm\t\tAvailable" << endl;
        }
    }
    cout<<endl;
}

void Reservation ::editReservation() // This function allow the user to change some reservation Info 
{                                   
    int found = 0 , Confirmed = 0 ; 
    int numR, choose;
    string newName, newContactNum;
    int newDay, newTime, newPeopleNum;

    cout << "\nTo edit the information of a reservation , Please enter number of reservation: #";
    cin >> numR;
    for (int i = 0; i <= rear; i++)
    {
        if (numOfReservation[i].numberOfReservation == numR )
        { 
            if(numOfReservation[i].statusOfReservation== "Confirmed") // to edit an information status should be Confirmed
                  {
                    cout << "\nWhat part you want to alter it ?\n \n";
                    cout << "1- Name of reservation\n";
                    cout << "2- Day of reservation\n";
                    cout << "3- Time of reservation\n";
                    cout << "4- Number of people\n";
                    cout << "5- Contact number\n\n";
                    cout << "Please choose number :";
                    cin >> choose;
                    cout << endl;
                    switch (choose)
                    {
                        case 1: // to alter Name 
                            cout << "Enter new Name: ";
                            cin >> newName;
                            numOfReservation[i].name = newName;
                            break;
                        case 2: // to alter Day 
                            cout << "Enter new Day: ";
                            cin >> newDay;
                            if (newDay > 31 || newDay < 1) // to check if the entry of Day is correct
                            {
                                cout << "Wrong Day "<<endl;
                                break;
                            }
                            if (check(newDay, numOfReservation[i].timeOfReservation)) // to check if Day not chosen by another reservation
                            {
                                cout << "This Day is already chosen by another reservation, try another time" << endl;
                                break;
                            }
                            numOfReservation[i].dayOfReservation = newDay;
                            break;
                        case 3: // to alter Time 
                            cout << "Enter new Time: ";
                            cin >> newTime;
                            if (numOfReservation[i].timeOfReservation > 12) // to check if the entry of Time is correct
                            {
                                cout << "Wrong time "<<endl;
                                break;
                            }
                            if (check(numOfReservation[i].dayOfReservation, numOfReservation[i].timeOfReservation))  // to check if Time not chosen by another reservation
                            {
                                cout << "This Time is already chosen by another reservation, try another time" << endl;
                                break;
                            }
                            numOfReservation[i].timeOfReservation = newTime;
                            break;
                        case 4: // to alter Number Of People
                            cout << "Enter Number Of People: ";
                            cin >> newPeopleNum;
                            numOfReservation[i].numberOfPeople = newPeopleNum;
                            break;
                        case 5: // to alter contact Number
                            cout << "Enter new Contact Number: ";
                            cin >> newContactNum;
                            if (numOfReservation[i].contactNumber.length() != 10) // to check if the entry of Contact Number correct
                            {
                                cout << "Wrong entry of contact number "<<endl;
                                break;
                            }
                            numOfReservation[i].contactNumber = newContactNum;
                            break;
                        default: // if the user choose wrong number for alteration
                            cout << "Wrong Entry." << endl;
                    }

            cout << endl;
            Confirmed = 1 ;
        }
            found = 1;
        }
    }
    
    if(found == 0) // if the reservation number not found
    { 
        cout << "\nThere is no #" << numR << " Reservation\n\n";
        
    }
    else if (Confirmed == 0) // if the reservation status not Confirmed (user can not alter Cancelled or Completed reservation)
    { 
        cout << "\nThe information of reservation #" << numR << " can not be changed (it is Completed or Cancelled)\n\n";
    }
}

int main()
{
  Reservation Res ;
  int choice = 0 ; 
  string name ;
  int numberRes ;
  do {
  cout << "\tWelcome to the Restaurant Reservation System (RRS)"<<endl;
cout << "\nPlease choose from the following menu:"<<endl;
cout << "1- Add reservation"<<endl;
cout << "2- Search for a reservation"<<endl;
cout << "3- Make a payment"<<endl;
cout << "4- Cancel a reservation"<<endl;
cout << "5- Daily Income"<<endl;
cout << "6- Display All Reservation For Day"<<endl;
cout << "7- Edit information of a reservation"<<endl;
cout <<"8- Exit "<<endl;
cout <<"Choose : "; 
cin>>choice ;
switch(choice){
  case 1 : Res.AddReservation(); break ;
  case 2 : cout<<"Please Enter number Of Reservation : " ; cin>>numberRes ;Res.search(numberRes); break ;
  case 3 : cout<<"Please Enter number Of Reservation : " ; cin>>numberRes ; Res.makePayment(numberRes) ; break;
  case 4 : cout<<"Please Enter name Of Reservation : " ;cin>>numberRes ; Res.cancelReservation(numberRes) ; break ;
  case 5 : Res.dailyIncome(); break ;
  case 6 : Res.displayAllReservationForDay(); break;
  case 7 : Res.editReservation(); break;
  case 8 : cout<<"\n\tThank you ! " <<endl;cout<<"Terminate Restaurant Reservation System (RRS) " <<endl;break;
  default :cout<<"Invalid choice " <<endl ;}
}while(choice != 8);
    return 0;
    
}
