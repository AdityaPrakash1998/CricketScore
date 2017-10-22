#include<bits/stdc++.h>
#include<cstdlib>
#include<string>
#include<fstream>
#include<windows.h>

using namespace std;

static int team1score=0;
static int team2score=0;
static int overs;
bool in=0;

void printScore(string a,string b,int team1score,int team2score,bool as,int wicket1,int wicket2)
{
    cout<<"\t\t\t##########################################################"<<endl;
    cout<<"\t\t\t##########################################################"<<endl;
    cout<<endl;
    cout<<"\t\t\t"<<a<<"  "<<team1score<<"/"<<10-wicket1<<endl;
    if(as==1)
    cout<<"\t\t\t"<<b<<"  "<<team2score<<"/"<<10-wicket2<<endl;
    else
     cout<<"\t\t\t"<<b<<"  "<<team2score<<"/"<<10-wicket2<<"\tYet to bat"<<endl;
     cout<<endl;
    cout<<"\t\t\t##########################################################"<<endl;
    cout<<"\t\t\t##########################################################\n\n\n\n\n"<<endl;
}

void printResult(string name1,string name2)
{
    system("CLS");
    system("title Result");
    cout<<"Match over\a"<<endl;

    if(team1score>team2score)
        cout<<"\t\t\t\t\t"<<name1<<" wins\n\n\n\n\n"<<endl;
    else
        cout<<"\t\t\t\t\t"<<name2<<" wins\n\n\n\n\n"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    system("color B1");
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
        cout<<"How many overs in each inning? "<<endl;
        cin>>overs;
        int balls=6*overs;
        system("CLS");
        system("color A1");
        SetConsoleTitle( TEXT( "TOSS" ) );
        cout<<"Which team is batting first ?\t"<<name1<<" or "<<name2<<" ?"<<endl;
        cin>>x;
        system("CLS");
        SetConsoleTitle( TEXT( "Match Started" ) );
        cout<<"\a";
        if(x==name1)
        {
            int wickets1=10;
            int wickets2=10;
            string temp;
            while(balls && wickets1)
            {
                printScore(name1,name2,team1score,team2score,in,wickets1,wickets2);
                cout<<"What happened on this delivery?"<<endl;
                cout<<"Wd for WideBall\nW for wicket\nNb for NO ball\nOr runs scored( <=0 )"<<endl;
                cout<<"WdW for WideBall+Wicket\nNbW for NO ball+Wicket\nWd(Runs) for Wideball+Runs\nNb(Runs) for NOball+Runs "<<endl;
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
                    wickets1--;
                    balls--;
                }
                else if(temp=="WdW")
                {
                    wickets1--;
                    team1score++;
                }
                else if(temp=="NbW")
                {
                    wickets1--;
                    team1score++;
                }
                else if(temp[0]=='W' && temp[1]=='d')
                {
                    team1score++;
                    team1score+=((int)temp[2]-48);
                }
                else if(temp[0]=='N' && temp[1]=='b')
                {
                    team1score++;
                    team1score+=((int)temp[2]-48);
                }
                else
                {
                    team1score+=((int)temp[0]-48);
                    balls--;
                }

                system("CLS");
            }
            cout<<"First Inning over\a"<<endl;
            in=1;
            balls=6*overs;

            while(balls && wickets2)
            {
                printScore(name1,name2,team1score,team2score,in,wickets1,wickets2);
                cout<<"What happened on this delivery?"<<endl;
                cout<<"Wd for WideBall\nW for wicket\nNb for NO ball\nOr runs scored( <=0 )"<<endl;
                cout<<"WdW for WideBall+Wicket\nNbW for NO ball+Wicket\nWd(Runs) for Wideball+Runs\nNb(Runs) for NOball+Runs "<<endl;
                cin>>temp;
                if(temp=="Wd")
                {
                    team2score++;
                }
                else if(temp=="Nb")
                {
                    team2score++;
                }
                else if(temp=="W")
                {
                    wickets2--;
                    balls--;
                }
                else if(temp=="WdW")
                {
                    wickets2--;
                    team2score++;
                }
                else if(temp=="NbW")
                {
                    wickets2--;
                    team2score++;
                }
                else if(temp[0]=='W' && temp[1]=='d')
                {
                    team2score++;
                    team2score+=((int)temp[2]-48);
                }
                else if(temp[0]=='N' && temp[1]=='b')
                {
                    team2score++;
                    team2score+=((int)temp[2]-48);
                }
                else
                {
                    team2score+=((int)temp[0]-48);
                    balls--;
                }

                system("CLS");
                if(team2score>team1score)
                {
                    printResult(name1,name2);
                    break;
                }
            }

        }
        else
        {
            int wickets2=10;
            int wickets1=10;
            string temp;
            while(balls && wickets2)
            {
                printScore(name2,name1,team2score,team1score,in,wickets2,wickets1);
                cout<<"What happened on this delivery?"<<endl;
                cout<<"Wd for WideBall\nW for wicket\nNb for NO ball\nOr runs scored( <=0 )"<<endl;
                cout<<"WdW for WideBall+Wicket\nNbW for NO ball+Wicket\nWd(Runs) for Wideball+Runs\nNb(Runs) for NOball+Runs "<<endl;
                cin>>temp;
                if(temp=="Wd")
                {
                    team2score++;
                }
                else if(temp=="Nb")
                {
                    team2score++;
                }
                else if(temp=="W")
                {
                    wickets2--;
                    balls--;
                }
                else if(temp=="WdW")
                {
                    wickets2--;
                    team2score++;
                }
                else if(temp=="NbW")
                {
                    wickets2--;
                    team2score++;
                }
                else if(temp[0]=='W' && temp[1]=='d')
                {
                    team2score++;
                    team2score+=((int)temp[2]-48);
                }
                else if(temp[0]=='N' && temp[1]=='b')
                {
                    team2score++;
                    team2score+=((int)temp[2]-48);
                }
                else
                {
                    team2score+=((int)temp[0]-48);
                    balls--;
                }

                system("CLS");
            }
            cout<<"First Inning over\a"<<endl;
            in=1;
            balls=6*overs;
            while(balls && wickets1)
            {
                printScore(name2,name1,team2score,team1score,in,wickets2,wickets1);
                cout<<"What happened on this delivery?"<<endl;
                cout<<"Wd for WideBall\nW for wicket\nNb for NO ball\nOr runs scored( <=0 )"<<endl;
                cout<<"WdW for WideBall+Wicket\nNbW for NO ball+Wicket\nWd(Runs) for Wideball+Runs\nNb(Runs) for NOball+Runs "<<endl;
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
                    wickets1--;
                    balls--;
                }
                else if(temp=="WdW")
                {
                    wickets1--;
                    team1score++;
                }
                else if(temp=="NbW")
                {
                    wickets1--;
                    team1score++;
                }
                else if(temp[0]=='W' && temp[1]=='d')
                {
                    team1score++;
                    team1score+=((int)temp[2]-48);
                }
                else if(temp[0]=='N' && temp[1]=='b')
                {
                    team1score++;
                    team1score+=((int)temp[2]-48);
                }
                else
                {
                    team1score+=((int)temp[0]-48);
                    balls--;
                }

                system("CLS");
                if(team1score>team2score)
                {
                    printResult(name1,name2);
                    break;
                }
            }

        }


        printResult(name1,name2);

        ofstream file("Data.dat",ios::app);
        file<<name1<<"\t"<<team1score<<endl;
        file<<name2<<"\t"<<team2score<<endl;

        if(team1score>team2score) file<<name1<<" wins"<<endl;
        else file<<name2<<" wins"<<endl;
        file.close();

    }
    else
    {
        cout<<"Would you like to know the previous match's result ?\n Enter YES or NO"<<endl;
        cin>>x;
        if(x=="YES" || x=="yes" || x=="y" || x=="Y")
        {
            system("CLS");
            ifstream file("Data.dat");
            string temp;
            while(getline(file,temp))
            {
                cout<<temp<<endl;
            }

            file.close();
        }
        else
        {
            cout<<"Thanks for using!"<<endl;
            exit(0);
        }

    }
}
