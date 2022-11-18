#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a,i=0;
    string name,text,age,old,password,password1,password2,password3,user,word,word1;
    string b[2],c[2];

    cout<<"----------SECURITY SYSTEM----------"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"|          1.Register             |"<<endl;
    cout<<"|          2.Login                |"<<endl;
    cout<<"|          3.Forget password      |"<<endl;
    cout<<"|          4.Exit                 |"<<endl;
    cout<<"-----------------------------------"<<endl;


    do
    {
        cout<<endl<<endl;
        cout<<"Enter your choice:-"<<endl;
        cin>>a;
        switch(a)
        {
        case 1:{

            cout<<"|---------------------------|"<<endl;
            cout<<"|---------Register----------|"<<endl;
            cout<<"|---------------------------|"<<endl;
            cout<<"Please enter your user name"<<endl;
            cin>>name;
            cout<<"Please enter your password"<<endl;
            cin>>password;
            cout<<"Please enter your age"<<endl;
            cin>>age;

            ofstream of1;
            of1.open("file.txt");      //used to store details of user
            if(of1.is_open())
            {
                of1<<name<<"\n";
                of1<<password;
                cout<<"Registration Successful"<<endl;
            }
            break;
        }
        case 2:{
            i=0;
            cout<<"|----------------------------|"<<endl;
            cout<<"|---------LogIn--------------|"<<endl;
            cout<<"|----------------------------|"<<endl;
            cout<<endl<<endl;
            ifstream of2;             //if stream used to read details contain in files
            of2.open("file.txt");
            cout<<"Please enter your username"<<endl;
            cin>>user;
            cout<<"Please enter your password"<<endl;
            cin>>password1;

            if(of2.is_open())
            {
                while(!of2.eof())     //from this eof we can detect when the end of file is reached.it return non 0 when end of file reached.
                {
                    while(getline(of2,text))     //getline is used to read the file line by line
                    {
                        istringstream iss(text);    // This istringstream object is used to stream the string and store it using extration of greater
                        iss>>word;                //We are storing the data in word
                        b[i]=word;
                        i++;
                    }
                    if(user==b[0] && password1==b[1])
                    {
                        cout<<"-------Log In Successful----";
                        cout<<endl<<endl;

                        cout<<"details:"<<endl;

                        cout<<"Username:"<<user<<endl;
                        cout<<"Password:"<<password1<<endl;
                        cout<<"Age:"<<age<<endl;
                    }
                    else
                    {

                        cout<<endl<<endl;
                        cout<<"Incorrect Credentials"<<endl;
                        cout<<"|     1.Press 2 to Login           |"<<endl;
                        cout<<"|     2.Press 3 to Change Password |"<<endl;
                        break;
                    }

                }
            }

        break;
        }
        case 3:
            {
                i=0;
                cout<<"-----------Change Password------------"<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the Old Password:"<<endl;
                cin>>old;
                if(of0.is_open())
                {
                    while(!of0.eof())
                    {
                        while(getline(of0,text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            c[i]=word1;
                            i++;
                        }
                        if(old==c[1])
                        {
                            of0.close();
                            ofstream of1; //ofstream is used to open and write something
                            of1.open("file.txt");
                            if(of1.is_open())
                            {
                                cout<<"Enter your new password:"<<endl;
                                cin>>password2;
                                cout<<"Enter your password again:"<<endl;
                                cin>>password3;

                                if(password2==password3)
                                {
                                    of1<<c[0]<<"\n";       //overwriting
                                    of1<<password2;
                                    cout<<"Password changed successfully"<<endl;
                                }
                                else      //if password is same as previous password it does not overwrite
                                {
                                    of1<<c[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match or password is same as previous pass"<<endl;
                                }
                            }
                         }
                         else
                         {
                             cout<<"Please Enter Valid Password"<<endl;
                             break;
                         }
                    }
                }
                break;
            }
        case 4:
            {
                cout<<"----------THANKYOU!---------"<<endl;
                break;

            }
        default:
            cout<<"Enter a valid choice"<<endl;

        }
    }

    while(a!=4);      //it will run the program until the user will not enter option 4.

    return 0;
}
