#include<bits/stdc++.h>
#include<cstdlib>
#include<string>
#include<fstream>
#include<windows.h>

using namespace std;

static int team1score=0;
static int team2score=0;
static int overs;


int main()
{
    string x;
    cout<<"Would you like to update information of new match ?\n Enter YES or NO"<<endl;
    cin>>x;
    if(x=="YES" || x=="yes" || x=="y" || x=="Y")
    {
        string name1,name2;
        cout<<"Enter the name of first team"<<endl;
        cin.ignore();
        getline(cin,name1,'\n');
        cout<<"Enter the name of second team"<<endl;
        getline(cin,name2,'\n');
        cout<<"How many overs in each innings? "<<endl;
        cin>>overs;
        int balls=6*overs;
        system("CLS");
        cout<<name1<<endl<<name2;
        SetConsoleTitle( TEXT( "Match Started" ) );
        cout<<"Which team is batting first ?\t 1 or 2 ?"<<endl;
        cin>>x;
        if(x=="1")
        {
            int wickets=10;
            string temp;
            while(balls && wickets)
            {
                cout<<"What happened in this delivery?"<<endl;
                cout<<"Wd for WideBall\t W for wicket\t Nb for NO ball\t Or runs scored( <=0 )"<<endl;
                cin>>temp;
                if(temp=="Wd")
                {
                    team1score++;
                }
                else if(temp=="Nb")
                {
                    team1score++;
                }
                else if(temp=="W")
                {
                    wickets--;
                    balls--;
                }
                else
                {
                    team1score+=((int)temp[0]-48);
                    balls--;
                }
            }
        }

    }
    else
    {
        cout<<"Would you like to know the previous match's result ?\n Enter YES or NO"<<endl;
        cin>>x;
        if(x=="YES" || x=="yes" || x=="y" || x=="Y")
        {

        }
        else
        {
            cout<<"Thanks for using!"<<endl;
            exit(0);
        }

    }
}
