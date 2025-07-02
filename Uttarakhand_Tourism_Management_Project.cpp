#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<stdbool.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

using namespace std;

class admin
{
    private:
        string password;
        string AdminName;
    public:
        bool verifyAdmin()
        {
            string admin="Akshita Khanduri";
            string password;
            int attempt = 3;
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|             Admin Login                     |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Enter Name: " << RESET;
            cin.ignore();
            getline(cin,AdminName);

            if (AdminName==admin) 
            {
                cout << setw(60) << " " << CYAN << "Enter Password: " << RESET;
                getline(cin,password);
                if (password == "ak@123")
                {
                    cout << setw(60) << " " << GREEN << "Login Successful!" << RESET << endl;
                    Sleep(2000);
                    return true;
                }
                else
                {
                    cout << setw(60) << " " << RED << "Incorrect Password. Try Again!" << RESET << endl;
                    Sleep(2000);
                    while (attempt > 0)
                    {
                        cout << setw(60) << " " << CYAN << "Enter Password: (Attempt left " << attempt << ")  " << RESET;
                        getline(cin,password);

                        if (password == "ak@123")
                        {
                            cout << setw(60) << " " << GREEN << "Login Successful!" << RESET << endl;
                            return true;
                        }
                        else
                        {
                            attempt--;
                            if (attempt > 0)
                                cout << setw(60) << " " << RED << "Incorrect Password. Try Again!" << RESET << endl;
                        }
                    }
                }
                cout << setw(60) << " " << RED << "Too many failed attempts. Account Locked for this session." << RESET << endl;
                Sleep(1500);
                return false;
            }
            else{
                cout << setw(60) << " " << RED<<"Invalid Admin credentials.Try again..."<<endl;
                Sleep(2000);
                return false;
            }
        }


        string getAdminName()
        {
            return AdminName;
        }

        string getPassword() {return password;}

        void checkTourist()
        {
            system("CLS");
            ifstream touristFile("tourist.txt");
            if(!touristFile)
            {
                cout << setw(60) << " " << RED << "No Tourist Found." << RESET << endl;
                Sleep(2000);
                return;
            }

            string touristName;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|           List of Tourists                  |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            while(getline(touristFile,touristName))
            {
                cout<<setw(60)<<touristName<<endl;
            }
            cout << setw(60) << " " << GREEN << "Press Enter to return to the menu..." << RESET;
            cin.ignore();
            cin.get();
            return;

            touristFile.close();
        }

        void viewFeedback()
        {
            system("CLS");
            ifstream file("feedback.txt");
            if(!file)
            {
                cout << setw(60) << " " << RED << "No Feedback Available." << RESET << endl;
                Sleep(2000);
                return;
            }
            else
            {
                string feedback;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|                 Feedback                    |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                while(getline(file,feedback))
                {
                    cout<<setw(60)<< " " << CYAN << feedback<<endl;
                }
                file.close();
                cout << setw(60) << " " << GREEN << "Press Enter to return to the menu..." << RESET;
                cin.ignore();
                cin.get();
            }
        }

        void viewBookings()
        {
            system("CLS");
            ifstream file("bookings.txt");
            if(!file)
            {
                cout << setw(60) << " " << RED << "No Bookings Found!" << RESET << endl;
                Sleep(1500);
                return;
            }
            string bookings;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|                 Bookings                    |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            while(getline(file,bookings))
            {
                cout<<setw(60)<<" "<<bookings<<endl;
            }
            file.close();
            cout << setw(60) << " " << GREEN << "Press Enter to return to the menu..." << RESET;
            cin.ignore();
            cin.get();
        }

};

class User
{
    protected:
        string userName;
        string password;
        bool isLoggedIn = false;
    public:
        void registerUser()
        {
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|            User Registration                |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Enter Name: " << RESET;
            cin.ignore();
            getline(cin,userName);
            cout << setw(60) << " " << CYAN << "Enter Password: " << RESET;
            getline(cin,password);

            ofstream file("user.txt",ios::app);
            if(file)
            {
                file<<userName<<","<<password<<endl;
                cout << setw(60) << " " << GREEN << "You have Registered Successfully!" << RESET << endl;
                Sleep(2000);
            }
            else
                cout << setw(60) << " " << RED << "Error: Unable to register successfully!" << RESET << endl;
            file.close();

        }


        bool verifyUser() 
        {
            string tempUser, tempPassword;
            int attempt = 3;
            system("CLS");

            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|               User Login                    |" << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << endl;
            cout << setw(60) << " " << CYAN << "Enter Name: ";
            
            string userName, password;
            cin.ignore();
            getline(cin, userName);

            ifstream file("user.txt");
            if (file) {
                bool flag = false;
                string line;

                while (getline(file, line)) 
                {
                    stringstream ss(line);
                    getline(ss, tempUser, ',');       
                    getline(ss, tempPassword);       

                    if (tempUser == userName) {
                        flag = true;
                        break;
                    }
                }
                file.close();

                if (!flag) {
                    cout << setw(60) << RED << " " << "              User Not Found!" << endl;
                    Sleep(1500);
                    return false;
                }

                while (attempt > 0) 
                {
                    cout << setw(60) << " " << CYAN << "Enter Password (" << attempt << " attempts left): ";
                    getline(cin, password);

                    if (tempPassword == password) 
                    {
                        cout << setw(60) << " " << GREEN << "Login Successfully!" << endl;
                        isLoggedIn = true;
                        Sleep(1500);
                        return true;
                    } 
                    else {
                        attempt--;
                        if (attempt > 0) 
                        {
                            cout << setw(60) << " " << RED << "Incorrect Password. Try Again!" << endl;
                            Sleep(2000);
                        }
                    }
                }

                cout << setw(60) << " " << "Too many failed attempts. Access Denied." << endl;
                Sleep(2000);
                return false;
            } 
            else {
                cout << setw(60) << " " << "Error: Unable to open user file!" << endl;
                return false;
            }
        }

        void logout() 
        {
            isLoggedIn = false; 
            userName.clear(); 
            password.clear(); 
        }

        bool checkIfLogin() 
        {
            cout<< setw(60) << " " << CYAN << "Enter Name: "<< RESET;
            cin.ignore();
            getline(cin,userName);
            cout<< setw(60) << " " << CYAN <<"Enter Password: "<< RESET;
            getline(cin,password);

            ifstream file("user.txt");
            if (file) 
            {
                string line;
                while (getline(file, line)) 
                {
                    stringstream ss(line);
                    getline(ss, userName, ','); 
                    getline(ss, password);
                    isLoggedIn = true; 
                    return true;
                }
                file.close();
            }
        }

        bool isUser_LoggedIn() 
        {
            if (checkIfLogin())
                return isLoggedIn; 
        }


        string getUserName() const
        {
            return userName;
        }

        void setUserName(const string &name) 
        {
            userName = name;
        }
    
};

class Tourist : public User
{
    private:
        string phNo,emailId,address,password;
    public:

        void registerTourist()
        {
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|            Tourist Registration             |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Enter Name: " << RESET;
            cin.ignore();
            getline(cin,userName);
            cout << setw(60) << " " << CYAN << "Enter Password: " << RESET;
            getline(cin,password);
            cout << setw(60) << " " << CYAN << "Enter Phone Number: " << RESET;
            getline(cin,phNo);
            cout << setw(60) << " " << CYAN << "Enter Email ID: " << RESET;
            getline(cin,emailId);
            cout << setw(60) << " " << CYAN << "Enter Address: " << RESET;
            cin.ignore();
            getline(cin, address);

            ofstream file("tourist.txt",ios::app);
            if(file)
            {
                file<<"******TOURIST DETAILS******"<<endl;
                file<<"Name: "<<userName<<endl;
                file<<"Phone Number: "<<phNo<<endl;
                file<<"Email Id: "<<emailId<<endl;
                file<<"Address: "<<address<<endl;
                file<<"***************************"<<endl;
                cout << setw(60) << " " << GREEN << "You have Registered Successfully!" << RESET << endl;
                Sleep(2000);
            }
            else{
                cout << setw(60) << " " << RED << "Error: Unable to register successfully!" << RESET << endl;
            }
            file.close();
        }

        void displaySubMenu(int choice) 
        {
            system("CLS");
            switch(choice) 
            {
                case 1:
                    cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "|         Adventure in the Alps               |" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "Uttarakhand, the land of majestic mountains\n" 
                         << setw(60) << " " << CYAN << "and serene rivers, invites adventurers to explore\n" 
                         << setw(60) << " " << CYAN << "its breathtaking landscapes. From thrilling\n"
                         << setw(60) << " " << CYAN << "white-water rafting in Rishikesh to serene treks\n" 
                         << setw(60) << " " << CYAN << "through lush valleys, every experience here\n" 
                         << setw(60) << " " << CYAN << "is a celebration of nature's beauty and the spirit\n" 
                         << setw(60) << " " << CYAN << "of adventure. - Thrilling Adventures Await" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "1. Rishikesh (Rafting, Bungee Jumping)" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "2. Auli (Skiing, Trekking)" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "3. Chopta (Trekking, Camping)" << RESET << endl;
                    break;

                case 2:
                    cout << setw(60) << " " << BLUE << BOLD << "+-------------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "|  Embrace the Essence of Heritage in Uttarakhand |" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "+-------------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "Uttarakhand, a vibrant blend of ancient traditions\n"
                        << setw(60) << " " << CYAN << "and breathtaking landscapes, invites you to explore\n"
                        << setw(60) << " " << CYAN << "its sacred temples, colorful festivals, and warm\n"
                        << setw(60) << " " << CYAN << "local communities. Immerse yourself in the rich\n"
                        << setw(60) << " " << CYAN << "cultural tapestry, where every experience resonates\n"
                        << setw(60) << " " << CYAN << "with the spirit of the Himalayas." << RESET << endl;
                    cout << setw(60) << " " << GREEN << "1. Pithoragarh (Local Handicrafts)" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "2. Dehradun (Historic Sites)" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "3. Mussoorie (Colonial-era architecture, Vibrant Markets)" << RESET << endl;
                    break;

                case 3:
                    cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "|     Holy Heights of Uttarakhand             |" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "Uttarakhand, the land where the divine meets\n"
                        << setw(60) << " " << CYAN << "the serene, invites you to embark on a spiritual\n"
                        << setw(60) << " " << CYAN << "journey amidst the majestic Himalayas. Here,\n"
                        << setw(60) << " " << CYAN << "every temple whispers ancient tales, and the\n"
                        << setw(60) << " " << CYAN << "tranquil rivers flow with the essence of peace,\n"
                        << setw(60) << " " << CYAN << "guiding your soul towards enlightenment." << RESET << endl;
                    cout << setw(60) << " " << GREEN << "1. Haridwar (Ganga Arti)" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "2. Kedarnath (Char Dham Yatra)" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "3. Badrinath (Char Dham Yatra)" << RESET << endl;
                    break;

                case 4:
                    cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "|              Into the Wild                  |" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "Explore the diverse wildlife of Uttarakhand,\n"
                        << setw(60) << " " << CYAN << "where lush forests and majestic mountains are\n"
                        << setw(60) << " " << CYAN << "home to tigers, elephants, and rare species.\n"
                        << setw(60) << " " << CYAN << "Experience thrilling safaris in Jim Corbett\n"
                        << setw(60) << " " << CYAN << "National Park and discover the rich biodiversity\n"
                        << setw(60) << " " << CYAN << "that makes this region a nature lover's paradise." << RESET << endl;
                    cout << setw(60) << " " << GREEN << "1. Jim Corbett National Park" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "2. Rajaji National Park" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "3. Nanda Devi Biosphere Reserve" << RESET << endl;
                    break;

                case 5:
                    cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "|              Nature's Abode                 |" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "Immerse yourself in the breathtaking beauty of\n"
                        << setw(60) << " " << CYAN << "Uttarakhand, where lush valleys, towering\n"
                        << setw(60) << " " << CYAN << "mountains, and pristine rivers create a paradise\n"
                        << setw(60) << " " << CYAN << "for nature lovers. Experience serene treks,\n"
                        << setw(60) << " " << CYAN << "vibrant flora, and tranquil landscapes that\n"
                        << setw(60) << " " << CYAN << "rejuvenate the soul and inspire adventure." << RESET << endl;
                    cout << setw(60) << " " << GREEN << "1. Chamoli (Valley of Flowers)" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "2. Nainital (Lakes and Hills)" << RESET << endl;
                    cout << setw(60) << " " << GREEN << "3. Mussoorie (Queen of Hills)" << RESET << endl;
                    break;

                default:
                    cout << setw(60) << " " << RED << "Invalid Choice. Returning to Main Menu" << RESET << endl;
                    return;
            }
            cout << setw(60) << " " << CYAN << "Press Enter to return to the Destinations Menu..." << RESET;
            cin.get();
        }

        void viewDestination()
        {
            int choice;
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|          Explore Destinations Menu          |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "1. Adventure in the Alps" << RESET << endl;
            cout << setw(60) << " " << CYAN << "2. Heritage and Culture" << RESET << endl;
            cout << setw(60) << " " << CYAN << "3. Spiritual Journeys" << RESET << endl;
            cout << setw(60) << " " << CYAN << "4. Wildlife Exploration" << RESET << endl;
            cout << setw(60) << " " << CYAN << "5. Scenic Beauty" << RESET << endl;
            cout << setw(60) << " " << CYAN << "6. Back to Menu" << RESET << endl;
            cout << setw(60) << " " << GREEN << "Enter your Choice: " << RESET;
            cin>>choice;
            cin.ignore();
            if(choice==6)
            {
                cout << setw(60) << " " << CYAN << "Returning to User Menu..." << RESET << endl;
                Sleep(2000);
                return;
            }
            if(choice>=1 && choice<=5)
                displaySubMenu(choice);
        }

        void bookDestination() 
        {
            Sleep(2000);
            system("CLS");
            registerTourist();
            ifstream file("destinations.txt");
            if (!file.is_open()) 
            {
                cout << "Error opening destinations file!" << endl;
                return;
            }
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "********** AVAILABLE DESTINATIONS **********" << RESET << endl;

            string name, location;
            int price;
            int index = 1;
            bool destinationsAvailable = false;

            while (file >> name >> location >> price)
            {
                cout << setw(60) << " " << CYAN << index << ". " << name << " in " << location << " - Price: " << price << endl;
                index++;
                destinationsAvailable = true;
            }
            file.close();

            if (!destinationsAvailable) 
            {
                cout << setw(60) << " " << RED << "No destinations available to book." << RESET << endl;
                return;
            }

            int choice;
            cout << setw(60) << " " << GREEN << "Enter the number of the destination you want to book: " << RESET;
            cin >> choice;

            ifstream fileAgain("destinations.txt");
            ofstream bookingFile("bookings.txt", ios::app);
            int currentIndex = 1;
            bool found = false;

            while (fileAgain >> name >> location >> price) 
            {
                if (currentIndex == choice) 
                {
                    cout<< setw(60) <<" " << CYAN << "You have selected " << name << " in " << location << " for " << price << RESET << endl;

                    string userName, bookingDate;
                    cout << setw(60) <<" "<< CYAN << "Enter your name: " << RESET;
                    cin.ignore();
                    getline(cin,userName);
                    cout << setw(60) <<" "<< CYAN << "Enter booking date (DD/MM/YYYY): " << RESET;
                    getline(cin,bookingDate);

                    bookingFile << userName << " " << name << " " << location << " " << price << " " << bookingDate << endl;

                    ofstream userFile(userName + "_expenditure.txt", ios::app);
                    if (userFile) 
                    {
                        userFile << "Destination: " << name << ", Location: " << location << ", Price: " << price << endl;
                        userFile.close();
                    }

                    cout << setw(60) << " " << GREEN << "Booking confirmed for " << name << " in " << location << "!" << RESET << endl;
                    Sleep(2000);

                    found = true;
                    break;
                }
                currentIndex++;
            }

            fileAgain.close();
            bookingFile.close();

            if (!found) {
                cout << setw(60) << " " << RED << "Invalid selection. Booking failed." << RESET << endl;
            }

            cout << setw(60) << " " << CYAN << "Press Enter to return to the User Menu..." << RESET;
            cin.get();
        }

        void cancleBooking()
        {
            string delDest;
            cout << setw(60) << " " << CYAN << "Enter the destination you want to cancel: " << RESET;
            cin.ignore();
            getline(cin,delDest);
            ifstream file("bookings.txt");
            if(!file)
            {
                cout << setw(60) << " " << RED << "No Booking Found." << RESET << endl;
                return;
            }
            
            ofstream tempfile("temp.txt");
            string str;
            int flag=0;

            while(getline(file,str))
            {
                if(str==delDest)
                    flag=1;
                else    
                    tempfile<<str<<endl;
            }
            file.close();
            tempfile.close();
            
            if(flag==1)
            {
                remove("bookings.txt");
                rename("temp.txt","bookings.txt");
                cout << setw(60) << " " << GREEN << "Booking for " << delDest << " has been cancelled successfully!" << RESET << endl;
            }
            else{
                remove("temp.txt");
                cout << setw(60) << " " << RED << "No Booking Found for " << delDest << "!" << RESET << endl;
            }

            cout << setw(60) << " " << CYAN << "Press Enter to return to the User Menu..." << RESET;
            cin.get();
        }

        void viewBookingHistory() 
        {
            cout<< setw(60) << " "  << CYAN << "Enter Name: "<< RESET;
            cin.ignore();
            getline(cin,userName);

            ifstream file(userName + ".txt");
            string line;

            cout << setw(60) << " "  << CYAN << "Your Booking History:\n";
            if (file) 
            {
                while (getline(file, line)) 
                {
                    cout<< setw(60) << " " << CYAN << "- " << line << endl;
                }
                file.close();
            } 
            else {
                cout<< setw(60) << " " << RED << "No bookings found.\n";
            }
            cin.ignore();
            cout << setw(60) << " " << CYAN << "Press Enter to return to the User Menu..." << RESET;
            cin.get();
        }

        void provideFeedback()
        {
            string feedback;
            cout << setw(60) << " " << CYAN << "Enter your feedback: " << RESET;
            cin.ignore();
            getline(cin,feedback);
            ofstream file("feedback.txt",ios::app);
            if(file)
            {
                file<<feedback<<endl;
                cout << setw(60) << " " << GREEN << "Thank you for your valuable feedback!" << RESET << endl;;
            }
            else
            {
                cout << setw(60) << " " << RED << "Error: Unable to save feedback." << RESET << endl;
            }
            file.close();

            cout << setw(60) << " " << CYAN << "Press Enter to return to the User Menu..." << RESET;
            cin.get();
        }

        void showLocalCusineAndFestivals()
        {
            Sleep(2000);
            int choice;
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+-------------------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|  Welcome to  Cultural and Culinary Experience of UK   |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+-------------------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "1. Local Cuisine" << RESET << endl;
            cout << setw(60) << " " << CYAN << "2. Cultural Festivals" << RESET << endl;
            cout << setw(60) << " " << CYAN << "3. Back" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Please Select an Option: " << RESET;
            cin>>choice;

            switch(choice)
            {
                case 1:
                    showLocalCusine();
                    break;
                case 2:
                    showCulturalFestivals();
                    break;
                case 3:
                    cout << setw(60) << " " << YELLOW << "Going back to the previous menu..." << RESET << endl;
                    Sleep(1000);
                    break;
                default:
                    cout << setw(60) << " " << RED << "Invalid Choice. Please try again." << RESET << endl;
                    Sleep(1500);
                    showLocalCusineAndFestivals();
                    break;
            }
            cin.ignore();
        }

       void showLocalCusine() 
       {
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|       Local Cuisine of Uttarakhand          |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << GREEN << "1. Aloo ke Gutke" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - A delicious potato dish made with boiled potatoes,\n"
                << setw(60) << " " << CYAN << "     seasoned with local spices, and fried to perfection." << RESET << endl;
            cout << setw(60) << " " << GREEN << "2. Chainsoo" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - A rich and aromatic lentil dish made with roasted Urad dal,\n"
                << setw(60) << " " << CYAN << "     slow-cooked in an iron pot for an earthy flavor." << RESET << endl;
            cout << setw(60) << " " << GREEN << "3. Bal Mithai" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - A famous sweet dish made from khoya, coated with sugar balls,\n"
                << setw(60) << " " << CYAN << "     often enjoyed as a dessert or snack." << RESET << endl;
            cout << setw(60) << " " << GREEN << "4. Singodi" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - A sweet delicacy prepared from khoya, sugar, and grated coconut,\n"
                << setw(60) << " " << CYAN << "     wrapped in a molu leaf for aroma and freshness." << RESET << endl;
            cout << setw(60) << " " << GREEN << "5. Thichwani" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - A traditional dish made with crushed radish and potatoes,\n"
                << setw(60) << " " << CYAN << "     cooked with sautéed onions and tomatoes." << RESET << endl;
            cout << setw(60) << " " << MAGENTA << "Enjoy the authentic flavors of Uttarakhand!" << RESET << endl;
            cin.ignore();
            cout << setw(60) << " " << CYAN << "Press Enter to return back..." << RESET;
            cin.get();
            showLocalCusineAndFestivals();
        }

        void showCulturalFestivals() 
        {
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|    Cultural Festivals of Uttarakhand        |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << GREEN << "1. Makar Sankranti" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - Celebrated in January, marks the end of winter and\n"
                << setw(60) << " " << CYAN << "     the beginning of the harvest season." << RESET << endl;
            cout << setw(60) << " " << GREEN << "2. Nanda Devi Mela" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - Dedicated to Goddess Nanda Devi, featuring processions,\n"
                << setw(60) << " " << CYAN << "     dances, and local rituals in the Kumaon region." << RESET << endl;
            cout << setw(60) << " " << GREEN << "3. Baisakhi" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - Marks the start of the new harvest season, celebrated\n"
                << setw(60) << " " << CYAN << "     with prayers, music, and dance in April." << RESET << endl;
            cout << setw(60) << " " << GREEN << "4. Kail Devta Fair" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - A folk festival in Garhwal, celebrated with songs,\n"
                << setw(60) << " " << CYAN << "     dances, and rituals honoring Kail Devta." << RESET << endl;
            cout << setw(60) << " " << GREEN << "5. Phool Dei" << RESET << endl;
            cout << setw(60) << " " << CYAN << "   - Spring festival in March where young girls sprinkle\n"
                << setw(60) << " " << CYAN << "     flowers and offer blessings for prosperity." << RESET << endl;
            cout << setw(60) << " " << MAGENTA << "Celebrate the vibrant traditions of Uttarakhand!" << RESET << endl;
            cin.ignore();
            cout << setw(60) << " " << CYAN << "Press Enter to return back..." << RESET;
            cin.get();
            showLocalCusineAndFestivals();
        }

        void showSoloTrips()
        {
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|         Solo Tourist Features               |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "1. Guided Trekking Tours to Kedarnath and Valley of Flowers." << RESET << endl;
            cout << setw(60) << " " << CYAN << "2. Meditation and Yoga Retreats in Rishikesh." << RESET << endl;
            cout << setw(60) << " " << CYAN << "3. Adventure Sports: Paragliding, Bungee Jumping, and Rafting." << RESET << endl;
            cout << setw(60) << " " << CYAN << "4. Local Culinary Experiences and Cultural Festivals." << RESET << endl;
            cout << setw(60) << " " << CYAN << "5. Wildlife Safaris in Jim Corbett National Park." << RESET << endl;
            cout << setw(60) << " " << CYAN << "6. Personalized Itineraries for Solo Travelers." << RESET << endl;
            cin.ignore();
            cout << setw(60) << " " << MAGENTA << "Press Enter to return back..." << RESET;
            cin.get();
        }

};


class BookHotel
{
    protected:
        static string HotelServices;
        static double HotelAmount;

    public:
        int choice,days;
        void book()     
        {
            system("CLS");
            ifstream file("hotel.txt");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|        Available Hotels in Uttarakhand      |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            
            if (file) {
                string hotelDetails;
                int index=1;
                while (getline(file, hotelDetails)) 
                {
                    cout << setw(60) << " " << GREEN <<  index << ". " <<  hotelDetails << RESET << endl;
                    index++;
                }
                file.close();
            } 
            else {
                cout << setw(60) << " " << RED << "Error loading hotel details." << RESET << endl;
            }
            
            cout << setw(60) << " " << CYAN << "Enter your choice to book a hotel: " << RESET;
            cin >> choice;
            cout<<endl;
            cout << setw(60) << " " << MAGENTA << "Lets proceed to Hotel Booking Services..." << RESET <<endl;
            Sleep(3000);
            system("CLS");  
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|     Uttarakhand Hotel Booking Services      |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Choose a Package" << RESET << endl;
            cout << setw(60) << " " << GREEN << "1. Standard Package - Rs 5,000 per day" << RESET << endl;
            cout << setw(60) << " " << GREEN << "2. Premium Package - Rs 10,000 per day" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Enter your Choice: " << RESET;
            cin>>choice;
            switch(choice)
            {
                case 1:
                    cout << setw(60) << " " << MAGENTA << "You have selected Standard Package" << RESET << endl;
                    cout << setw(60) << " " << MAGENTA << "Price: 5,000 per day" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "Facilities included:\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Comfortable 3-star hotel stay.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Guided tours to major attractions.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Complimentary breakfast.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Transportation between key destinations.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "Enter no of days: " << RESET;
                    cin>>days;
                    HotelAmount+=5000*days;
                    HotelServices+="Standard Package booked - Rs. "+ to_string(HotelAmount);
                    cin.ignore();
                    cout << setw(60) << " " << MAGENTA << "Press Enter to return back..." << RESET;
                    cin.get();
                    break;
                case 2:
                    cout << setw(60) << " " << MAGENTA << "You have selected Premium Package" << RESET << endl;
                    cout << setw(60) << " " << MAGENTA << "Price: 10,000 per day" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "Facilities included:\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Luxury 5-star hotel stay.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Exclusive private tours.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- All meals included with local delicacies.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Personalized itinerary planning.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Airport pick-up and drop-off.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "Enter no of days: " << RESET;
                    cin>>days;
                    HotelAmount+=10000*days;
                    HotelServices+="Standard Package booked - Rs. "+ to_string(HotelAmount);
                    cout << setw(60) << " " << GREEN << "Your booking has been registered successfully..." << RESET;
                    cin.ignore();
                    cout << setw(60) << " " << MAGENTA << "Press Enter to return back..." << RESET;
                    cin.get();
                    break;
                default:
                    cout << setw(60) << " " << RED << "Invalid Choice" << RESET << endl;
                    cout << setw(60) << " " << RED << "Redirecting to Main Menu" << RESET << endl;;
                    return;
            }

    }

        string getHotelServices() const
        {
            return HotelServices;
        }

};

string BookHotel::HotelServices;
double BookHotel::HotelAmount;

class bookCab
{
    protected:
        static string CabServices;
        static double CabAmount;

    public:
        int choice,days;
        void book() 
        {
            system("CLS");
            ifstream cabFile("cabs.txt");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|         Available Cabs in Uttarakhand       |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;

            if (cabFile) {
                string cabDetails;
                int index=1;
                while (getline(cabFile, cabDetails)) 
                {
                    cout << setw(60) << " " << GREEN <<  index << ". " << cabDetails << RESET << endl;
                    index++;
                }
                cabFile.close();
            } 
            else {
                cout << setw(60) << " " << RED << "Error loading cab details." << RESET << endl;
            }

            cout << setw(60) << " " << MAGENTA << "Lets proceed to Cab Booking Services..." << RESET <<endl;
            Sleep(3000);
            system("CLS"); 

            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|        Uttarakhand Cab Booking Services     |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << GREEN << "1. Book Standard Cab - Rs 2,000 per day" << RESET << endl;
            cout << setw(60) << " " << GREEN << "2. Book Luxurious Cab - Rs 40,000 per day" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
            cin >> choice;

            switch(choice)
            {
                case 1:
                    cout << setw(60) << " " << MAGENTA << "Standard Cab has been Booked" << RESET << endl;
                    cout << setw(60) << " " << MAGENTA << "Price: Rs 2,000 per day" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "Services Include" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "- Comfortable ride with a professional driver.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Transportation to key destinations.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "Enter no of days: " << RESET;
                    cin >> days;
                    CabAmount += 2000 * days;
                    CabServices += "Standard Cab booked - Rs. " + to_string(CabAmount);
                    cin.ignore();
                    cout << setw(60) << " " << CYAN << "Press Enter to return back..." << RESET;
                    cin.get();
                    break;

                case 2:
                    cout << setw(60) << " " << MAGENTA << "Luxurious Cab has been Booked" << RESET << endl;
                    cout << setw(60) << " " << MAGENTA << "Price: Rs 40,000 per day" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "Services Include" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "- Premium luxury ride with all amenities.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Personalized chauffeur service.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Exclusive transport to luxury destinations.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "Enter no of days: " << RESET;
                    cin >> days;
                    CabAmount += 40000 * days;
                    CabServices += "Luxurious Cab booked - Rs. " + to_string(CabAmount);
                    cout << setw(60) << " " << GREEN << "Your booking has been registered successfully..." << RESET;
                    cin.ignore();
                    cout << setw(60) << " " << MAGENTA << "Press Enter to return back..." << RESET;
                    cin.get();
                    break;

                default:
                    cout << setw(60) << " " << RED << "Invalid Choice" << RESET << endl;
                    cout << setw(60) << " " << RED << "Redirecting to Main Menu" << RESET << endl;
                    return;
 
            }
        }

        string getCabServices() const
        {
            return CabServices;
        }
};

string bookCab::CabServices;
double bookCab::CabAmount;

class hireGuide
{
    protected:
        static string GuideServices;
        static double GuideAmount;

    public:
        int choice,days;
        void book() 
        {
            system("CLS");
            ifstream guideFile("guides.txt");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|      Available Guides in Uttarakhand      |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;

            if (guideFile) 
            {
                string guideDetails;
                int index=1;
                while (getline(guideFile, guideDetails)) {
                    cout << setw(60) << " " << GREEN << index << ". " << guideDetails << RESET << endl;
                    index++;
                }
                guideFile.close();
            } 
            else {
                cout << setw(60) << " " << RED << "Error loading guide details." << RESET << endl;
            }

            cout << setw(60) << " " << GREEN << "Lets proceed to Guide Booking Services..." << RESET <<endl;
            Sleep(3000);
            system("CLS");
            
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|       Uttarakhand Guide Booking Services    |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Guide Service Options" << RESET << endl;
            cout << setw(60) << " " << GREEN << "1. Half Day Guide - Rs 2,000 per day" << RESET << endl;
            cout << setw(60) << " " << GREEN << "2. Full Day Guide - Rs 4,000 per day" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
            cin>>choice;
            switch(choice)
            {
                case 1:
                    cout << setw(60) << " " << MAGENTA << "You have hired a guide for a half-day tour" << RESET << endl;
                    cout << setw(60) << " " << MAGENTA << "Price: Rs 2,000 per day" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD << "Services Include" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "- Expert guide with local knowledge.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Tour of major attractions for half a day.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "Enter no of days: " << RESET;
                    cin>>days;
                    GuideAmount+=2000*days;
                    GuideServices+="Half day Guide Hired - Rs. "+ to_string(GuideAmount);
                    cin.ignore();
                    cout << setw(60) << " " << CYAN << "Press Enter to return back..." << RESET;
                    cin.get();
                    break;
                case 2:
                    cout << setw(60) << " " << MAGENTA << "You have hired a guide for a full-day tour" << RESET << endl;
                    cout << setw(60) << " " << MAGENTA << "Price: Rs 4,000 per day" << RESET << endl;
                    cout << setw(60) << " " << BLUE << BOLD <<"Services Include" << RESET << endl;
                    cout << setw(60) << " " << CYAN << "- Expert guide with in-depth knowledge of the area.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "- Full-day tour across key cultural and historical sites.\n" << RESET;
                    cout << setw(60) << " " << CYAN << "Enter no of days: " << RESET;
                    cin>>days;
                    GuideAmount+=4000*days;
                    GuideServices+="Full day Guide Hired  - Rs. "+ to_string(GuideAmount);
                    cout << setw(60) << " " << GREEN << "Your booking has been registered successfully..." << RESET;
                    cin.ignore();
                    cout << setw(60) << " " << MAGENTA << "Press Enter to return back..." << RESET;
                    cin.get();
                    break;
                default:
                    cout << setw(60) << " " << RED << "Invalid Choice" << RESET << endl;
                    cout << setw(60) << " " << RED << "Redirecting to Main Menu" << RESET << endl;
                    return;
            }

        }

        string getGuideServices() const
        {
            return GuideServices;
        }
        
};

string hireGuide::GuideServices;
double hireGuide::GuideAmount;



class printReceipt: public BookHotel, public bookCab, public hireGuide, public User
{
    public:

        void generateReceipt()
        {
            string username;
            cin.ignore();
            cout<< setw(60)<< " " << CYAN <<"Enter Name: "<<RESET;
            getline(cin,username);

            system("CLS");

            if (username.empty()) 
            {
                cout << "Error: User not logged in. Cannot generate receipt." << endl;
                Sleep(2000);
                return;
            }

            double totalAmount = BookHotel::HotelAmount + bookCab::CabAmount + hireGuide::GuideAmount;
            double destinationTotal = 0.0;


            
            ifstream userExpenditureFile(username + "_expenditure.txt"); 
            string line;

            if (userExpenditureFile) {
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|       UTTRAKHAND TOURISM MANAGEMENT         |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << GREEN << "----------------------------- Receipt Details -----------------------------------"<<RESET<<endl;
                cout<< setw(60) <<" " << MAGENTA << "Destination Booked by "<<RESET <<endl;
                cout<< setw(60) <<" " << MAGENTA << "Tourist Name: "<< userName<<RESET<<endl;
                while (getline(userExpenditureFile, line)) {
                    
                    
                    cout << setw(60) << " " << CYAN << line << endl;
                    
                    size_t pos = line.find("Price: ");
                    if (pos != string::npos) {
                        double price = stod(line.substr(pos + 7)); 
                        destinationTotal += price;
                    }
                }
                userExpenditureFile.close();
            } else {
                cout << "No expenditure details found for user." << endl;
            }

            totalAmount += destinationTotal; 
    
            ofstream file(username + ".txt");
            if (file)
            {
                file << "Extra Services Booked: " << endl;
                file << BookHotel::HotelServices << endl; 
                file << bookCab::CabServices << endl; 
                file << hireGuide::GuideServices << endl; 
                file << "Total Expenditure: " << fixed << setprecision(2) << totalAmount << endl;
                file << "---------------------------------------------" << endl;
                file.close();
                Sleep(2000);
            }
            else
            {
                cout << setw(60) << " " << RED << "Error: Unable to generate Receipt" << RESET << endl;
                Sleep(2000);
            }

            ifstream inFile(username + ".txt");
            if (inFile) 
            {
                while (getline(inFile, line)) {
                    cout << setw(60) << " " << MAGENTA << line << endl;
                }
                inFile.close();
                cout << setw(60) << " " << GREEN << "Receipt generated Successfully for " << username << RESET << endl;
                cin.ignore();
                cout << setw(60) << " " << CYAN << "Press Enter to return back..." << RESET;
                cin.get();
            } 
            else {
                cout << "Error: Could not read the receipt file.\n";
            }
            
        }
        
};


class Feedback
{
    private:
        map<string,pair<int,string>> feedback;
    
    public:
        void collectFeedback(const string &username)
        {
            system("CLS");

            int rating;
            string comment;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|              FEEDBACK FORM                  |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Please rate your experience: (1-5): " << RESET;
            cin>>rating;
            cin.ignore();
            cout << setw(60) << " " << CYAN << "Please Enter your Feedback: " << RESET;
            getline(cin,comment);
            feedback[username]=make_pair(rating,comment);

            ofstream file("feedback.txt",ios::app);
            if(file)
            {
                file<<"*****************"<<endl;
                file<<"Name: "<<username<<endl;
                file<<"Rating: "<<rating<<endl;
                file<<"Feedback: "<<comment<<endl;
                file<<"*****************"<<endl;
            }
            else{
                cout<<"Error: Unable to open file"<<endl;
            }
            file.close();
            cout << setw(60) << " " << GREEN << "Thank You for your Feedback" << RESET << endl;
            cin.ignore();
            cout << setw(60) << " " << CYAN << "Press Enter to return back..." << RESET;
            cin.get();

        }

        void showFeedback()
        {
            system("CLS");
            string str;
            ifstream file("feedback.txt");
            if(file)
            {
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|          Tourist Feedback Received          |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;                
                while(getline(file,str))
                {
                    cout<<setw(60) << " " << CYAN <<str<<endl;
                }
                file.close();
                cin.ignore();
                cout << setw(60) << " " << MAGENTA << "Press Enter to return back..." << RESET;
                cin.get();
            }
            else{
                cout << setw(60) << " " << RED << "No Feedback Available" << RESET << endl;
            }
        }
};

class management
{
    private:
        User u;
        BookHotel h;
        bookCab c;
        hireGuide g;
        printReceipt r;
        Feedback f;
        admin a;
        Tourist t;

    public:
        management()
        {
            system("CLS");
           
            cout << setw(60) << " " << BLUE << BOLD << "+----------------------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|         WELCOME TO UTTRAKHAND TOURISM MANAGEMENT         |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+----------------------------------------------------------+" << RESET << endl;

            cout << endl;
            cout << setw(60) << " " << CYAN << "Thank you for choosing " << BOLD << "Uttarakhand Tourism Services!" << RESET << endl;
            cout << setw(60) << " " << CYAN << "We are here to make your journey memorable and enjoyable." << RESET << endl;
            cout << setw(60) << " " << CYAN << "Let us guide you through the beauty of Uttarakhand." << RESET << endl;
            cout << endl;

            cout << setw(60) << " " << GREEN << "Initializing services";
            for (int i = 0; i < 3; i++) {
                cout << ".";
                Sleep(1000); 
            }
            cout << RESET << endl;

            cout << setw(60) << " " << MAGENTA << "Loading your personalized tourism experience..." << RESET << endl;
            Sleep(3000);

            startSystem();
        }


        void startSystem()
        {
            string userName,password;
            int choice;
            system("cls");
            while(true)
            {
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|               MAIN MENU                     |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << "1. Admin " << RESET << endl;
                cout << setw(60) << " " << BLUE << "2. User(Tourist) " << RESET << endl;
                cout << setw(60) << " " << BLUE << "3. Exit - Close the application." << RESET << endl;

                cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                cin>>choice;

                switch(choice)
                {
                    case 1:
                        if(a.verifyAdmin())
                        {
                            cout << setw(60) << " " << GREEN << "+---------------------------------------------+" << RESET << endl;
                            cout << setw(60) << " " << GREEN << "|            WELCOME ADMIN                    |" << RESET << endl;
                            cout << setw(60) << " " << GREEN << "+---------------------------------------------+" << RESET << endl;
                            adminMenu();
                        }
                        else{
                            Sleep(2000);
                            system("CLS");
                        }
                        break;
                    case 2:
                        userLoginOrRegister();
                        break;
                    case 3:
                        cout << setw(60) << " " << GREEN << "Exiting application..." << RESET << endl;
                        exit(0);
                    default:
                        cout << setw(60) << " " << RED << "Invalid choice! Please try again" << RESET << endl;
                        system("CLS");
                        break;
                }
            }
        }

        void adminMenu()
        {
            int choice;
            do
            {
                system("CLS");
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|               ADMIN MENU                    |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << "1. View All Bookings" << RESET << endl;
                cout << setw(60) << " " << BLUE << "2. Manage Services (Hotel, Cab, Guide,Destinations)" << RESET << endl;
                cout << setw(60) << " " << BLUE << "3. View Feedback" << RESET << endl;
                cout << setw(60) << " " << BLUE << "4. Check Tourist" << RESET << endl;
                cout << setw(60) << " " << BLUE << "5. Exit - Log out from Admin" << RESET << endl;

                cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                cin>>choice;

                switch(choice)
                {
                    case 1:
                        a.viewBookings();
                        break;
                    case 2:
                        manageServices();
                        break;
                    case 3:
                        a.viewFeedback();
                        break;
                    case 4:
                        a.checkTourist();
                        break;
                    case 5:
                        cout << setw(60) << " " << GREEN << "Logging out from Admin..." << RESET << endl;
                        Sleep(2000);
                        startSystem();
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid choice! Please try again" << RESET << endl;
                        break; 
                }

            }while(choice!=4);

        }

        void userLoginOrRegister()
        {
            int choice;
            system("CLS");
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "|           USER LOGIN OR REGISTER            |" << RESET << endl;
            cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl; 
            cout << setw(60) << " " << BLUE << "1. Register - Create a new user account." << RESET << endl;
            cout << setw(60) << " " << BLUE << "2. Login - Access your account" << RESET << endl;
            cout << setw(60) << " " << BLUE << "3. Back - Go to Main Menu" << RESET << endl;
            cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
            cin>>choice;
            switch(choice)
            {
                case 1:
                    if (u.isUser_LoggedIn()) 
                    {
                        system("CLS");
                        Sleep(1000);
                        cout << setw(60) << " " << GREEN << "You are already logged in as " << u.getUserName() << "." << RESET << endl;
                        cout << setw(60) << " " << CYAN << "1. Logout" << RESET << endl;
                        cout << setw(60) << " " << CYAN << "2. Login "  << RESET << endl;
                        cout << setw(60) << " " << CYAN << "3. Back to Main Menu" << RESET << endl;
                        cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                        cin >> choice;
                        if (choice == 1) {
                            u.logout(); 
                            cout << setw(60) << " " << GREEN << "You have logged out successfully." << RESET << endl;
                            Sleep(2000);
                        }
            
                        else if(choice==2)
                        {
                            if(u.verifyUser())
                            {
                                userMenu();              
                            }
                            else{
                                cout << setw(60) << " " << RED << "Invalid credentials. Please try again!" << RESET << endl;
                                Sleep(2000);
                            }     
                        }
                        else if(choice==3)
                        {
                            startSystem();
                        }
                    }
                    u.registerUser();
                    break;
                case 2:
                    if(u.verifyUser())
                    {
                        userMenu();              
                    }
                    else{
                        cout << setw(60) << " " << RED << "Invalid credentials. Please try again!" << RESET << endl;
                        Sleep(2000);
                    }
                    break;
                case 3:
                    break;
            }while(choice!=3);
            
        }

        void userMenu()
        {
            int choice;
            do
            {
                system("CLS");
                cout << setw(60) << " " << BLUE << BOLD << "+-------------------------------------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|                             USER MENU                                   |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+-------------------------------------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << GREEN << "1. Tour Booking Services." << RESET << endl;
                cout << setw(60) << " " << CYAN << "\t\t- Book your tour to the beautiful destinations in Uttarakhand." << RESET << endl;
                cout << setw(60) << " " << CYAN << "\t\t- View available destinations, book your visit, and cancel bookings." << RESET << endl;
                cout << setw(60) << " " << GREEN << "2. Additional Services." << RESET << endl;
                cout << setw(60) << " " << CYAN << "\t\t- Book hotels, hire guides, book cabs." << RESET << endl;
                cout << setw(60) << " " << CYAN << "\t\t- Discover local cuisine, festivals, and solo traveler trips." << RESET << endl;
                cout << setw(60) << " " << GREEN << "3. Feedback and Billing" << RESET << endl;
                cout << setw(60) << " " << CYAN << "\t\t- Provide feedback and generate detailed bills." << RESET << endl;
                cout << setw(60) << " " << GREEN << "4. Exit - Log Out" << RESET << endl;
                cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                cin>>choice;

                switch(choice)
                {
                    case 1:
                        bookingMenu();
                        break;
                    case 2:
                        addServicesMenu();
                        break;
                    case 3:
                        feedbackAndBillingMenu();
                        break;
                    case 4:
                        cout << setw(60) << " " << GREEN << "Logging Out..." << RESET << endl;
                        startSystem();
                        break;
                }
            }while(choice!=4);
        }

        void bookingMenu()
        {
            int choice;
            do
            {
                system("CLS");
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|         TOUR BOOKING SERVICES               |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << CYAN << "1. View Destination - Explore tourist spots." << RESET << endl;
                cout << setw(60) << " " << CYAN << "2. Book Destination - Reserve your visit." << RESET << endl;
                cout << setw(60) << " " << CYAN << "3. Cancel Booking - Cancel your reservation." << RESET << endl;
                cout << setw(60) << " " << CYAN << "4. Browse Booking History - View your past bookings." << RESET << endl;
                cout << setw(60) << " " << CYAN << "5. Back - Return to User Menu." << RESET << endl;
                cout << setw(60) << " " << GREEN << "Enter your choice: " << RESET;
                cin>>choice;

                switch(choice)
                {
                    case 1:
                        t.viewDestination();
                        break;
                    case 2:
                        t.bookDestination();
                        break;
                    case 3:
                        t.cancleBooking();
                        break;
                    case 4:
                        t.viewBookingHistory();
                        break;
                    case 5:
                        userMenu();
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid Choice. Please try again." << RESET << endl;
                        break;
                }
            }while(choice!=4);

            userMenu();
        }

        void addServicesMenu()
        {
            int choice;
            do
            {
                system("CLS");
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|           ADDITIONAL SERVICES               |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << CYAN << "1. Book Hotels - Book a hotel for your stay in Uttarakhand." << RESET << endl;
                cout << setw(60) << " " << CYAN << "2. Hire Guide - Book a professional tour guide." << RESET << endl;
                cout << setw(60) << " " << CYAN << "3. Book Cab - Arrange transportation." << RESET << endl;
                cout << setw(60) << " " << CYAN << "4. Explore Local Cuisine and Festivals." << RESET << endl;
                cout << setw(60) << " " << CYAN << "5. Solo Trips - Plan trips specifically for solo travelers." << RESET << endl;
                cout << setw(60) << " " << CYAN << "6. Back - Return to User Menu" << RESET << endl;
                cout << setw(60) << " " << GREEN << "Enter your choice: " << RESET;
                cin>>choice;

                switch(choice)
                {
                    case 1:
                        h.book();
                        break;
                    case 2:
                        g.book();
                        break;
                    case 3:
                        c.book();
                        break;
                    case 4:
                        t.showLocalCusineAndFestivals();
                        break;
                    case 5:
                        t.showSoloTrips();
                        break;
                    case 6:
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid Choice. Please try again." << RESET << endl;
                        break;
                }
            }while(choice!=6);
            
            userMenu();
        }

        void feedbackAndBillingMenu()
        {
            int choice;
            do
            {
                system("CLS");
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|           FEEDBACK AND BILLING              |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << CYAN << "1. Provide Feedback - Share your experience of the services you availed." << RESET << endl;
                cout << setw(60) << " " << CYAN << "2. Generate Bill - View and print a detailed receipt of your bookings." << RESET << endl;
                cout << setw(60) << " " << CYAN << "3. Back - Return to User Menu" << RESET << endl;
                cout << setw(60) << " " << GREEN << "Enter your choice: " << RESET;
                cin>>choice;

                switch(choice)
                {
                    case 1:
                        f.collectFeedback(u.getUserName());
                        break;
                    case 2:

                        r.generateReceipt();
                        break;
                    case 3:
                        cout<< setw(60) << " " << MAGENTA << "Returning back to User Menu..."<< RESET << endl;
                        Sleep(1000);
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid choice! Please try again." << RESET << endl;
                        break;
                }
            }while(choice!=3);
            Sleep(2000);
            userMenu();
        }
        void manageServices()
        {
            Sleep(1000);
            int choice;
            do
            {
                system("CLS");
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|         ADMIN SERVICE MANAGEMENT            |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 1. Manage Hotels                            |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 2. Manage Cabs                              |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 3. Manage Guides                            |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 4. Manage Destinations                      |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 5. Back to Admin Menu                       |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                cin >> choice;

                switch(choice)
                {
                    case 1:
                        manageHotels();
                        break;
                    case 2:
                        manageCabs();
                        break;
                    case 3:
                        manageGuides();
                        break;
                    case 4:
                        manageDestinations();
                        break;
                    case 5:
                        cout << setw(60) << " " << GREEN << "Returning to Admin Menu..." << RESET << endl;
                        Sleep(1500);
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid choice, please try again." << RESET << endl;
                        break;
                }
            }while(choice!=5);

            adminMenu();
            

        }

        void manageHotels()
        {
            system("cls");
            int choice;
            do
            {
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|           HOTEL MANAGEMENT                  |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 1. Add New Hotel                            |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 2. Update Hotel Details                     |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 3. Delete Hotel                             |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 4. Back to Service Management Menu          |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                cin >> choice;

                switch (choice) 
                {
                    case 1:
                        addHotel();
                        break;
                    case 2:
                        updateHotel();
                        break;
                    case 3:
                        deleteHotel();
                        break;
                    case 4:
                        cout << setw(60) << " " << GREEN << "Returning to Service Management Menu..." << RESET << endl;
                        Sleep(1500);
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid choice, please try again." << RESET << endl;
                        break;
                
                }
            }while(choice!=4);
            manageServices();
        }

        void addHotel()
        {
            system("CLS");
            string name,loc;
            cout << setw(60) << " " << CYAN << "Enter Hotel Name: " << RESET;
            cin.ignore();
            getline(cin,name);
            cout << setw(60) << " " << CYAN << "Enter Hotel Location: " << RESET;
            getline(cin,loc);
            ofstream file("hotel.txt",ios::app);
            if(file)
            {
                file<<name<<" "<<loc<< " "<< endl;
                file.close();
                cout << setw(60) << " " << GREEN << "Hotel added successfully!" << RESET << endl;
                Sleep(2000);
            }
            else
            {
                cout << setw(60) << " " << RED << "Error: Unable to open file..." << RESET << endl;
            }
            manageHotels();
        }

        void updateHotel() 
        {
            system("cls");
            string name, loc;
            int rooms;
            cout << setw(60) << " " << CYAN << "Enter the hotel name to update: " << RESET;
            cin.ignore();
            getline(cin,name);
            ifstream file("hotels.txt");
            ofstream tempFile("temp.txt");
            bool found = false;

            if (file && tempFile) {
                string hotelName, hotelLocation;

                while (file >> hotelName >> hotelLocation) 
                {
                    if (hotelName == name) 
                    {
                        cout << setw(60) << " " << CYAN << "Updating hotel details..." << RESET << endl;
                        cout << setw(60) << " " << CYAN << "Enter new location: " << RESET;
                        getline(cin,loc);
                        tempFile<<hotelName<<" "<<loc<<" "<<endl;
                        found = true;
                    } 
                    else 
                    {
                        tempFile<<hotelName<<" "<<hotelLocation<<" "<<endl;
                    }
                }

                file.close();
                tempFile.close();

                remove("hotels.txt");
                rename("temp.txt", "hotels.txt");

                if (found) 
                {
                    cout << setw(60) << " " << GREEN << "Hotel details updated!" << RESET << endl;
                    Sleep(2000);
                } 
                else 
                {
                    cout << setw(60) << " " << RED << "Hotel not found!" << RESET << endl;
                }
            } 
            else {
                cout << "Error opening file!" << endl;
            }
            manageHotels(); 
        }   


        void deleteHotel()
        {
            system("cls");
            string name;
            cout << setw(60) << " " << CYAN << "Enter the Hotel name to delete: " << RESET;
            cin.ignore();
            getline(cin,name);

            ifstream file("hotels.txt");
            ofstream tempfile("temp.txt");
            bool flag=false;

            if(file && tempfile)
            {
                string tempName,loc;
                while(file>>tempName>>loc)
                {
                    if(tempName!=name)
                        tempfile<<name<<" "<<loc<<endl;
                    else
                        flag=true;
                }

                file.close();
                tempfile.close();

                remove("hotels.txt");
                rename("temp.txt","hotels.txt");

                if(flag){
                    cout << setw(60) << " " << GREEN << "Hotel deleted successfully!" << RESET << endl;
                    Sleep(2000);
                }
                else    
                    cout << setw(60) << " " << RED << "Hotel not found..." << RESET << endl;
            }
            else
                cout<<"Error: Unable to open file..."<<endl;
            manageHotels();

        }

        void manageCabs() 
        {
            system("cls");
            int choice;
            do
            {
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|            CAB MANAGEMENT                   |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 1. Add New Cab                              |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 2. Update Cab Details                       |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 3. Delete Cab                               |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 4. Back to Service Management               |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                cin >> choice;
                switch (choice) 
                {
                    case 1:
                        addCab();
                        break;
                    case 2:
                        updateCab();
                        break;
                    case 3:
                        deleteCab();
                        break;
                    case 4:
                        cout << setw(60) << " " << GREEN << "Returning to Service Management Menu..." << RESET << endl;
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid choice, please try again." << RESET << endl;
                        break;
                }
            }while(choice!=4);
            manageServices();
        }

        void addCab()
        {
            string type,model,licensePlate;
            cout << setw(60) << " " << CYAN << "Enter Cab Type: " << RESET;
            cin.ignore();
            getline(cin,type);
            cout << setw(60) << " " << CYAN << "Enter Cab Model: " << RESET;
            getline(cin,model);
            cout << setw(60) << " " << CYAN << "Enter Cab License Plate: " << RESET;
            getline(cin,licensePlate);

            ofstream file("cabs.txt",ios::app);
            if(file)
            {
                file<<type<<" "<<model<<" "<<licensePlate<<endl;
                file.close();
                cout << setw(60) << " " << GREEN << "Cab added successfully!" << RESET << endl;
                Sleep(2000);
            } 
            else 
                cout << setw(60) << " " << RED << "Error: Unable to open file" << RESET << endl;

            manageCabs();
        }

        void updateCab()
        {
            system("cls");
            string licensePlate,type,model;
            cout << setw(60) << " " << CYAN << "Enter Cab License Plate to Update: " << RESET;
            cin.ignore();
            getline(cin,licensePlate);

            ifstream file("cab.txt");
            ofstream tempfile("temp.txt");
            bool flag=false;
            if(file && tempfile)
            {
                string tempType,tempPlate,tempModel;
                while(file>>tempType>>tempModel>>tempPlate)
                {
                    if(tempPlate==licensePlate)
                    {
                        cout << setw(60) << " " << CYAN << "Enter New Cab Model: " << RESET;
                        cin >> model;
                        cout << setw(60) << " " << CYAN << "Enter New Cab Type: " << RESET;
                        cin>>type;
                        tempfile<<type<<" "<<model<<" "<<tempPlate<<endl;
                        flag=true;
                    }
                    else{
                        tempfile<<tempType<<" "<<tempModel<<" "<<tempPlate<<endl;
                    }
                }
                file.close();
                tempfile.close();

                remove("cabs.txt");
                rename("tempfile.txt","cab.txt");

                if (flag) {
                    cout << setw(60) << " " << GREEN << "Cab details updated successfully!" << RESET << endl;
                    Sleep(2000);
                }
                else 
                    cout << setw(60) << " " << RED << "Cab not found!" << RESET << endl;
            }
            else{
                cout<<"Error: Unable to open file."<<endl;
            }
            manageCabs();
        }

        void deleteCab()
        {
            system("cls");
            string licensePlate;
            cout << setw(60) << " " << CYAN << "Enter Cab License Plate to Delete: " << RESET;
            cin>>licensePlate;

            ifstream file("cabs.txt");
            ofstream tempfile("temp.txt");
            bool flag=false;

            if(file && tempfile)
            {
                string type,model,tempPlate;
                while(file>>type>>model>>tempPlate)
                {
                    if(tempPlate!=licensePlate)
                    {
                        tempfile<<type<<" "<<model<<" "<<tempPlate<<endl;
                    }
                    else    
                        flag=true;

                }
                file.close();
                tempfile.close();

                remove ("cabs.txt");
                rename("temp.txt","cabs.txt");
                if(flag){
                    cout << setw(60) << " " << GREEN << "Cab deleted successfully!" << RESET << endl;
                    Sleep(1500);
                }
                else    
                    cout << setw(60) << " " << RED << "Cab not found!" << RESET << endl;
            }
            else{
                cout<<"Error: Unable to open file..."<<endl;
            }
            manageCabs();
        }

        void manageGuides()
        {
            int choice;
            do
            {
                system("CLS");
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "|               GUIDE MANAGEMENT              |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 1. Add New Guide                            |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 2. Update Guide Details                     |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 3. Delete Guide                             |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "| 4. Back to Service Management Menu          |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD << "+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                cin>>choice;

                switch(choice)
                {
                    case 1:
                        addGuide();
                        break;
                    case 2:
                        updateGuide();
                        break;
                    case 3:
                        deleteGuide();
                        break;
                    case 4:
                        cout << setw(60) << " " << GREEN << "Returning to Service Management Menu..." << RESET << endl;
                        Sleep(2000);
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid Choice. Please try again..." << RESET << endl;
                        manageGuides();
                }
            }while(choice!=4);
            manageServices();
        }

        void addGuide()
        {
            system("CLS");
            string name, expertise, experience;

            cout << setw(60) << " " << CYAN << "Enter Guide Name: " << RESET;
            cin.ignore();
            getline(cin,name);
            cout << setw(60) << " " << CYAN << "Enter Guide Expertise: " << RESET;
            getline(cin,expertise);
            cout << setw(60) << " " << CYAN << "Enter Guide Experience (years): " << RESET;
            getline(cin,experience);

            ofstream file("guides.txt", ios::app);
            if (file) 
            {
                file<<name<<" "<<expertise<<" "<<experience<<endl;
                file.close();
                cout << setw(60) << " " << GREEN << "Guide added successfully!" << RESET << endl;
                Sleep(2000);
            } 
            else {
                cout << setw(60) << " " << RED << "Error opening file!" << RESET << endl;
            }
            manageGuides();
        }

        void updateGuide() 
        {
            system("CLS");
            string name, expertise;
            int experience;
            cout << setw(60) << " " << CYAN << "Enter Guide Name to Update: " << RESET;
            cin.ignore();
            getline(cin,name);
            ifstream file("guides.txt");
            ofstream tempFile("temp.txt");
            bool flag = false;

            if (file && tempFile) 
            {
                string guideName, guideExpertise;
                int guideExperience;

                while (file>>guideName>>guideExpertise>>guideExperience) 
                {
                    if (guideName == name) 
                    {
                        cout <<setw(60)<< "Updating guide details..." << endl;
                        cout << setw(60) << " " << CYAN << "Enter New Expertise: " << RESET;
                        getline(cin,expertise);
                        cout << setw(60) << " " << CYAN << "Enter New Experience (years): " << RESET;
                        cin>>experience;
                        tempFile << guideName << " " << expertise << " " << experience << endl;
                        flag = true;
                    } 
                    else {
                        tempFile<<guideName<<" "<<guideExpertise<<" "<<guideExperience<<endl;
                    }
                }

                file.close();
                tempFile.close();

                remove("guides.txt");
                rename("temp.txt", "guides.txt");

                if (flag) {
                    cout << setw(60) << " " << GREEN << "Guide details updated!" << RESET << endl;
                    Sleep(2000);
                } 
                else {
                    cout << setw(60) << " " << RED << "Guide not found!" << RESET << endl;
                }
            } 
            else {
                cout << "Error opening file!" << endl;
            }
            manageGuides();
        }

        void deleteGuide() 
        {
            system("CLS");
            string name;
            cout << setw(60) << " " << CYAN << "Enter Guide Name to Delete: " << RESET;
            cin.ignore();
            getline(cin,name);

            ifstream file("guides.txt");
            ofstream tempFile("temp.txt");
            bool found = false;

            if (file && tempFile) 
            {
                string guideName, guideExpertise;
                int guideExperience;

                while (file >> guideName >> guideExpertise >> guideExperience) 
                {
                    if (guideName != name) {
                        tempFile << guideName << " " << guideExpertise << " " << guideExperience << endl;
                    }
                    else {
                        found = true;
                    }
                }

                file.close();
                tempFile.close();

                remove("guides.txt");
                rename("temp.txt", "guides.txt");

                if (found) {
                    cout << setw(60) << " " << GREEN << "Guide deleted successfully!" << RESET << endl;
                    Sleep(2000);
                } 
                else {
                    cout << setw(60) << " " << RED << "Guide not found!" << RESET << endl;
                
                }
            } 
            else {
                cout << "Error opening file!" << endl;
            }
            manageGuides();
        }

        void manageDestinations() 
        {
            int choice;
            do 
            {
                system("CLS");
                cout << setw(60) << " " << BLUE << BOLD <<"+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD <<"|           DESTINATION MANAGEMENT            |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD <<"+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD <<"| 1. Add New Destination                      |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD <<"| 2. Update Destination Details               |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD <<"| 3. Delete Destination                       |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD <<"| 4. Back to Service Management Menu          |" << RESET << endl;
                cout << setw(60) << " " << BLUE << BOLD <<"+---------------------------------------------+" << RESET << endl;
                cout << setw(60) << " " << CYAN << "Enter your choice: " << RESET;
                cin >> choice;

                switch (choice) 
                {
                    case 1:
                        addDestination();
                        break;
                    case 2:
                        updateDestination();
                        break;
                    case 3:
                        deleteDestination();
                        break;
                    case 4:
                        cout << setw(60) << " " << GREEN << "Returning to Service Management Menu..." << RESET << endl;
                        Sleep(1500);
                        break;
                    default:
                        cout << setw(60) << " " << RED << "Invalid choice. Please try again." << RESET << endl;
                        Sleep(1500);
                }
            } while (choice != 4);
            manageServices();
        }


        void addDestination() 
        {
            system("cls");
            string name, location;
            int price;
            cout << setw(60) << " " << CYAN << "Enter destination name: " << RESET;
            cin.ignore();
            getline(cin,name);
            cout << setw(60) << " " << CYAN << "Enter destination location: " << RESET;
            getline(cin,location);
            cout << setw(60) << " " << CYAN << "Enter destination price: " << RESET;
            cin >> price;

            ofstream file("destinations.txt", ios::app);
            if (file) 
            {
                file << name << " " << location << " " << price << endl;
                file.close();
                cout << setw(60) << " " << GREEN << "Destination added successfully!" << RESET << endl;
                Sleep(2000);
            } 
            else {
                cout << "Error opening file!" << endl;
            }
            manageDestinations();
        }

        void updateDestination() 
        {
            system("CLS");
            string name, location;
            int price;
            cout << setw(60) << " " << CYAN << "Enter the destination name to update: " << RESET;
            cin.ignore();
            getline(cin,name); 

            ifstream file("destinations.txt");
            ofstream tempFile("temp.txt");
            bool found = false; 

            if (file && tempFile) 
            {
                string destName, destLocation;
                int destPrice;  
                while (file >> destName >> destLocation >> destPrice) 
                {
                    if (destName == name) {
                        cout << setw(60)<< "Updating destination details..." << endl;
                        cout << setw(60) << " " << CYAN << "Enter new location: " << RESET;
                        getline(cin,location);
                        cout << setw(60) << " " << CYAN << "Enter new price: " << RESET;
                        cin >> price;
                        tempFile << destName << " " << location << " " << price << endl;
                        found = true;
                    } 
                    else {
                        tempFile << destName << " " << destLocation << " " << destPrice << endl;
                    }
                }   
                file.close();
                tempFile.close();

                remove("destinations.txt");
                rename("temp.txt", "destinations.txt"); 

                if (found) {
                    cout << setw(60) << " " << GREEN << "Destination details updated successfully!" << RESET << endl;
                    Sleep(2000);
                } 
                else {
                    cout << setw(60) << " " << RED << "Destination not found!" << RESET << endl;
                    Sleep(2000);
                }
            } 
            else {
                cout << "Error opening file!" << endl;
            }
        }

        void deleteDestination() 
        {
            system("cls");
            string name;
            cout << setw(60) << " " << CYAN << "Enter the destination name to delete: " << RESET;
            cin.ignore();
            getline(cin,name);

            ifstream file("destinations.txt");
            ofstream tempFile("temp.txt");
            bool found = false;

            if (file && tempFile) 
            {
                string destName, destLocation;
                int destPrice;

                while (file >> destName >> destLocation >> destPrice) 
                {
                    if (destName != name) {
                        tempFile << destName << " " << destLocation << " " << destPrice << endl;
                    } else {
                        found = true;
                    }
                }

                file.close();
                tempFile.close();

                remove("destinations.txt");
                rename("temp.txt", "destinations.txt");

                if (found) {
                    cout << setw(60) << " " << GREEN << "Destination deleted successfully!" << RESET << endl;
                    Sleep(2000);
                } 
                else {
                    cout << setw(60) << " " << RED << "Destination not found!" << RESET << endl;
                    Sleep(2000);
                }
            } 
            else {
                cout << "Error opening file!" << endl;
            }
        }


};

int main()
{
    management M;
    return 0;
}