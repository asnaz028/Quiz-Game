/*MA-DSE-20.1F-020
MA-DSE-20.1F-028
MA-DSE-20.1F-044
MA-DSE-20.1F-050*/

#include<iostream>
#include<windows.h>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;

//*************************************
//          globally declared
//*************************************
char  name[100];
void Menu();
char guess_answer;
int total;
HANDLE colors=GetStdHandle(STD_OUTPUT_HANDLE);

//*************************************
//     sets the location of screen
//*************************************
void gotoXY(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Coordinates;
	Coordinates.X = x;
	Coordinates.Y = y;
	SetConsoleCursorPosition(console,Coordinates);
}

//*************************************
//         welcome interface
//*************************************
class Display
{
public:
    void Display1()
    {
        SetConsoleTextAttribute(colors,8);//change the color to ash
        gotoXY(2,5);
        //link:http://patorjk.com/software/taag/#p=display&f=Big&t=Welcome%20to%20the%20Game
        cout << R"(
                                 __          __  _                            _          _   _             _____
                                 \ \        / / | |                          | |        | | | |           / ____|
                                  \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |_| |__   ___  | |  __  __ _ _ __ ___   ___
                                   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  | __| '_ \ / _ \ | | |_ |/ _` | '_ ` _ \ / _ \
                                    \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |_| | | |  __/ | |__| | (_| | | | | | |  __/
                                     \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/   \__|_| |_|\___|  \_____|\__,_|_| |_| |_|\___|



        )";

        SetConsoleTextAttribute(colors,128);//change the color to text black,background grey
        cout<< R"(


                 .-''''-..                                                                                                                      _
               .' .'''.   `.                                                                                                                 .'/   \
              /    \   \    `.                                                                                                              / /     \
              \    '   |     |                                                                                                              | |     |
               `--'   /     /                                                                                                               | |     |
                    .'  ,-''                                                                                                                |/`.   .'
                    |  /                                                                                                                     `.|   |
                    | '                                                                                                                       ||_|
                    '-'                                                                                                                       |/_/
                   .--.                                                                                                                       .'.--.
                  /    \                                                                                                                     | |    |
                  \    /                                                                                                                     \_\    /
                   `--'                                                                                                                       `''--'

        )";

        //*********Entering the name**************************************
        SetConsoleTextAttribute(colors,7);//change the color to ash
        gotoXY(70,51);
        cout<<"Enter your Name: \n";
        gotoXY(65,53);
        cout<<"(Press enter to continue.) ";
        gotoXY(87,50);//move the  cursor up to the enter name
        cin.getline (name,100);

        //***********welcoming again to the game with the name of the player********************************
        SetConsoleTextAttribute(colors,7);//change the color to purple
        system("cls");
        gotoXY(62,7);
        cout<<"----------Welcome "<<name<<" to the Game----------"<<"\n\n";
}
};

//****************************************************
//       Declaring variables for the question
//****************************************************
class Question
{
private:
    string QuestionText;
    string answer1;
    string answer2;
    string answer3;
    string answer4;
    char correctAnswer;
    int questionScore;

public:
    void setValues( string q,  string a1,  string a2,  string a3,  string a4, char ca, int pa)
    {
    QuestionText = q;
    answer1 = a1;
    answer2 = a2;
    answer3 = a3;
    answer4 = a4;
    correctAnswer = ca;
    questionScore = pa;
    }
    void questionCall();
};

//**************************Format for possible answers displayed when program executes.*******************
void Question::questionCall()
{
    SetConsoleTextAttribute(colors,6);//Change color to yellow
    gotoXY(43,5);
    cout<<" ___________________________________________________________________________";
    gotoXY(43,6);
    cout<<"|  _______________________________________________________________________  |";
    gotoXY(43,7);
    cout<<"| |                                                                       | |";
    gotoXY(43,8);
    cout<<"| |                                                                       | |";
    gotoXY(43,9);
    cout<<"| |                                                                       | |";
    gotoXY(43,10);
    cout<<"| |_______________________________________________________________________| |";
    gotoXY(43,11);
    cout<<"|  ___________________________________   _________________________________  |";
    gotoXY(43,12);
    cout<<"| |                                   | |                                 | |";
    gotoXY(43,13);
    cout<<"| |                                   | |                                 | |";
    gotoXY(43,14);
    cout<<"| |___________________________________| |_________________________________| |";
    gotoXY(43,15);
    cout<<"|  ___________________________________   _________________________________  |";
    gotoXY(43,16);
    cout<<"| |                                   | |                                 | |";
    gotoXY(43,17);
    cout<<"| |                                   | |                                 | |";
    gotoXY(43,18);
    cout<<"| |___________________________________| |_________________________________| |";
    gotoXY(43,19);
    cout<<"|___________________________________________________________________________|";
    gotoXY(47,8);
    cout<<QuestionText;
    gotoXY(47,13);
    cout<<"a. "<<answer1;
    gotoXY(85,13);
    cout<<"b. "<<answer2;
    gotoXY(47,17);
    cout<<"c. "<<answer3;
    gotoXY(85,17);
    cout<<"d. "<<answer4;

    //********************User enters their answer.********************
    SetConsoleTextAttribute(colors,7);
    gotoXY(35,25);
     cout << "What is your answer?" << "\n";
     gotoXY(55,25);
     cin >> guess_answer;
    //*************If their answer is correct*************
    if (guess_answer == correctAnswer)
    {
        SetConsoleTextAttribute(colors,2);
        gotoXY(70,30);
        cout <<"YOUR ANSWER IS CORRECT!\n";
        total=total+questionScore;
        gotoXY(73,32);
        cout<<"Final score is: "<<total<<"\n";
    }
    else //If their answer is incorrect, message is displayed, no points added.
         //Correct answer displayed.
    {
        SetConsoleTextAttribute(colors,4);
        gotoXY(70,29);
        cout << "Sorry, you're wrong..." << "\n";
        gotoXY(69,31);
        cout << "The correct answer is " << correctAnswer << "." << "\n";
        total=total-0;
        gotoXY(71,33);
        cout<<"Final score is: "<<total;
    }

    SetConsoleTextAttribute(colors,7);
    gotoXY(110,35);
     cout << "Press enter to continue..." << "\n";
        cin.get();
         cin.ignore();
}
//*************************************
//            25 questions
//*************************************
class Question1
{
    public:
    Question1()
    {
        Question q1;
        Question q2;
        Question q3;
        Question q4;
        Question q5;
        Question q6;
        Question q7;
        Question q8;
        Question q9;
        Question q10;
        Question q11;
        Question q12;
        Question q13;
        Question q14;
        Question q15;
        Question q16;
        Question q17;
        Question q18;
        Question q19;
        Question q20;
        Question q21;
        Question q22;
        Question q23;
        Question q24;
        Question q25;

        q1.setValues("1. What is the largest river in the world?", "Nile", "Amazon", "Mahaweli river", "Ganges", 'a', 4);
        q2.setValues("2. The number of rings in the Olympic symbol is?", "4", "5", "6", "7", 'b', 4);
        q3.setValues("3. Pablo Picasso belonged to which country?", "France", "Germany", "Spain", "Italy", 'c', 4);
        q4.setValues("4. The number  of 3-digit numbers divisible by 6 is…..", "149", "166 ", "150 ", "151", 'c', 4);
        q5.setValues("5. Who invented aeroplane?", "Robbert Oppenheimer", "Kirkpatrick Macmillan", "Wallace Carothers", "Orville & Wilbur Wright", 'd', 4);
        q6.setValues("6. Who invented the printing press?", "Alexander Grahambel", "Johannes Gutenburg", "Grace Hopper", "Charles Babbage", 'b', 4);
        q7.setValues("7. What is the name of person which controls a football match?", "Referee ", "Umpire", "Spectator ", "Goalkeeper ", 'a', 4);
        q8.setValues("8. After a decade of writing Spanish songs, which artist reached\n\t\t\t\t\t\tinternational fame from 2001 onwards with English ones?", "Shakira","Rihanna ", "Jennifer Lopez", "Lady Gaga", 'a', 4);
        q9.setValues("9. 106 x 106 - 94 x 94?", "2004", "2400 ", "1904 ", "1906", 'b', 4);
        q10.setValues("10.In which year the 1st iphone released?", "2007", "1998", "2010", "1985", 'a', 4);
        q11.setValues("11. What is the smallest country in the world?", "Canada", "Russia", "Maldives", "Batticon City", 'd', 4);
        q12.setValues("12. Which of these players holds the record for highest number of\n\t\t\t\t\t\tOlympics gold medals?", "Usain Bolt", "Susanthika Jayasinghe", "Michael Phelps", "Paavo Nurmi", 'c', 4);
        q13.setValues("13. what is the first colour film in Srilanka?", "Gamperaliya", "Rekawa", "Ganga Addara", "Ranmuthu Duwa", 'd', 4);
        q14.setValues("14. Which of the following numbers given 240 when added to its  own\n\t\t\t\t\t\tsquares?", "15", "16", "18", "20", 'a', 4);
        q15.setValues("15. One kilobyte(KB) is equal to?", "1000 bits", "1024 bytes ", "1024 megabytes", "1024 gigabytes", 'b', 4);
        q16.setValues("16. Largest island in the indian ocean?", "Madagascar", "Maldives", "Srilanka", "Andaman City", 'a', 4);
        q17.setValues("17. Significant and celebrate sports figures of the 20th Century\n\t\t\t\t\t\tMuhammad Ali was associated with which sports?", "Judo", "Boxing ", "Swimming ", "Football", 'b', 4);
        q18.setValues("18. who won the best actor award at the Oscars award in 2020?", "Jonny Deep ", "Joaquin Phoenix ", "Leonardo DiCaprio", "Tom Cruise", 'b', 4);
        q19.setValues("19. What is always in front of you but can’t be seen?", "Air", "Smell", "Silence", "Future", 'd', 4);
        q20.setValues("20. What does www stands for?", "World wide weight", "World wide website", "World wide web", "World web wide", 'c', 4);
        q21.setValues("21. What is the first political part in srilanka?", "United national party", "Lanka sama samaja party", "Srilanka people freedom alliance", "National  congress", 'b', 4);
        q22.setValues("22. Which cricketer has taken most catches in ODI cricket Matches?", "Ricky Ponting", "Mahela Jayawardene", "Jacques Kallis", "Mark Waugh", 'b', 4);
        q23.setValues("23. Who is painting the Mona Lisa?", "Raphael", "Michelangelo ", "Leonardo da Vinci", "Donatello", '3', 4);
        q24.setValues("24. I can be cracked, I can be made. I can be told, I can be played.\n\t\t\t\t\t\tWhat am I?", "Egg", "Feelings", "Secret", "joke", 'd', 4);
        q25.setValues("25. Which of the following network protocols is described by GSM?", "2G", "3G", "4G", "5G", 'a', 4);

        q1.questionCall();system("cls");
        q2.questionCall();system("cls");
        q3.questionCall();system("cls");
        q4.questionCall();system("cls");
        q5.questionCall();system("cls");
        q6.questionCall();system("cls");
        q7.questionCall();system("cls");
        q8.questionCall();system("cls");
        q9.questionCall();system("cls");
        q10.questionCall();system("cls");
        q11.questionCall();system("cls");
        q12.questionCall();system("cls");
        q13.questionCall();system("cls");
        q14.questionCall();system("cls");
        q15.questionCall();system("cls");
        q16.questionCall();system("cls");
        q17.questionCall();system("cls");
        q18.questionCall();system("cls");
        q19.questionCall();system("cls");
        q20.questionCall();system("cls");
        q21.questionCall();system("cls");
        q22.questionCall();system("cls");
        q23.questionCall();system("cls");
        q24.questionCall();system("cls");
        q25.questionCall();system("cls");
    }
};

//*************************************
//      function for exit and home
//*************************************
void HomeOrExit()
{
    SetConsoleTextAttribute(colors,7);
    gotoXY(110,35);
            cout << "Press enter to continue..." << "\n";
            cin.get();
            cin.ignore();
            system("cls");
                SetConsoleTextAttribute(colors,6);//Change color to green
                string reply;
                gotoXY(25,17);
                cout<<"Do u want to exit or go back to Home menu?\n";
                gotoXY(22,19);
                cout<<"(Press 'H' to Home Menu/Press any key to exit)";
                gotoXY(69,17);
                cin>>reply;
                if(reply=="H"||reply=="h")
                {
                    system("cls");
                    Menu();
                }
                else
                {
                    SetConsoleTextAttribute(colors,2);
                    system("cls");
                    gotoXY(17,15);
                    cout<< R"(

                                 _____ _                 _                              ___                         _               _         _  _  _
                                /__   \ |__   __ _ _ __ | | __  _   _  ___  _   _      / __\___  _ __ ___   ___    /_\   __ _  __ _(_)_ __   / \/ \/ \
                                  / /\/ '_ \ / _` | '_ \| |/ / | | | |/ _ \| | | |    / /  / _ \| '_ ` _ \ / _ \  //_\\ / _` |/ _` | | '_ \ /  /  /  /
                                 / /  | | | | (_| | | | |   <  | |_| | (_) | |_| |_  / /__| (_) | | | | | |  __/ /  _  \ (_| | (_| | | | | /\_/\_/\_/
                                 \/   |_| |_|\__,_|_| |_|_|\_\  \__, |\___/ \__,_( ) \____/\___/|_| |_| |_|\___| \_/ \_/\__, |\__,_|_|_| |_\/ \/ \/
                                                                |___/            |/                                     |___/

                              )";
                    gotoXY(20,35);
                    exit(0);
}
}

//*************************************
//  play option containing questions
//*************************************
class Play: private Question
{
public:
    Play()
    {
        system("cls");
        string respond;
        gotoXY(20,10);
        cout<<"Are you ready to start the quiz, "<<name<<"?\n";
        gotoXY(19,12);
        cout<<"(Press 'y' for Yes/Press any key for No)"<<"\n";
        gotoXY(110,35);
        cout<<"Press enter to continue... ";

        gotoXY(60,10);
        cin>>respond;

        //**************If user says yes, the quiz begins.***********************
        if(respond=="y"||respond=="Y"||respond=="Yes"||respond=="yes")
        {
            gotoXY(30,19);
            SetConsoleTextAttribute(colors,2);//Change color to green

            cout<< R"(
                                                            _____ _____  ___________   _     _   _ _____  _   ___
                                                           |  __ \  _  ||  _  |  _  \ | |   | | | /  __ \| | / / |
                                                           | |  \/ | | || | | | | | | | |   | | | | /  \/| |/ /| |
                                                           | | __| | | || | | | | | | | |   | | | | |    |    \| |
                                                           | |_\ \ \_/ /\ \_/ / |/ /  | |___| |_| | \__/\| |\  \_|
                                                            \____/\___/  \___/|___/   \_____/\___/ \____/\_| \_(_)


                                                                         USE [a-d] TO ANSWER THE QUIZ!

                        )";

            SetConsoleTextAttribute(colors,7);//Change color to offwhite
            gotoXY(138,35);
            cin.get();
            cin.ignore();
            system("cls");
            Question1 Q1;
            }
            //*****************if user says no************
            else
            {
                HomeOrExit();
            }
            cout << "\n";
        }
};

//*************************************
//         RESULTS INTERFACE
//*************************************
class Result
{
public:
    Result()
    {
        SetConsoleTextAttribute(colors,4);
        cout<<R"(


                                                               __    __  __         __ _____
                                                              /__\  /__\/ _\/\ /\  / //__   \
                                                             / \// /_\  \ \/ / \ \/ /   / /\/
                                                            / _  \//__  _\ \ \_/ / /___/ /
                                                            \/ \_/\__/  \__/\___/\____/\/
       )";
       SetConsoleTextAttribute(colors,5);
        cout<<R"(





                                                    ¶1011¶¶¶¶¶¶¶¶¶¶¶11111111111111111111111¶10001¶¶1¶¶¶¶¶¶¶
                                                    101¶¶10¶¶       ¶¶¶¶¶¶¶10        11¶¶¶¶        ¶¶101101
                                                    01¶111¶¶         ¶11111¶¶¶¶0  1¶¶¶¶¶¶¶0         ¶000010
                                                    110011¶0      0 1¶                    ¶100      ¶10¶101
                                                    1101¶0¶¶    0¶¶¶¶                      ¶¶¶¶0  0¶¶101111
                                                    ¶¶01¶¶¶¶¶¶¶¶¶¶                             ¶¶¶¶1¶¶01¶¶1
                                                    000001¶                                          ¶101¶0
                                                    ¶¶¶¶¶¶¶                                          ¶¶¶110
                                                    ¶¶¶¶11¶                                         ¶¶01¶¶¶
                                                    000¶10¶¶                                        ¶10001¶
                                                    ¶¶1¶¶10¶¶                                      ¶¶0100¶¶
                                                    1100¶¶¶1¶¶                                    ¶10000¶¶¶
                                                        ¶¶111¶¶¶                                ¶¶¶111¶¶¶00
                                                        ¶¶00001¶¶¶                             ¶¶111¶11¶0
                                                        0¶¶00¶¶¶11¶¶                         ¶¶¶¶00001¶1
                                                         0¶¶¶¶     1¶¶¶                   ¶¶¶0  1¶¶1¶¶0
                                                           ¶¶        1¶¶¶               ¶¶¶0      ¶¶
                                                           1¶          0¶¶¶           ¶¶¶0        0¶
                                                            ¶1            1¶¶      ¶¶¶1           0¶
                                                            0¶¶10            1¶  ¶¶0             0¶1
                                                             01¶¶¶¶¶¶¶¶¶¶¶¶11¶¶¶¶¶111¶¶¶¶¶¶¶¶¶¶¶¶0

                 )";

                 SetConsoleTextAttribute(colors,7);

                    gotoXY(75,22);
                 cout<<"Name: "<<name;
                 gotoXY(75,23);
                 cout<<"Total: "<<total;

                 if(total>=60 & total<=100)
                 {
                     gotoXY(75,27);
                     cout<<"You passed!";
                 }
                 else
                 {
                     gotoXY(75,27);
                     cout<<"You Failed!";
                 }

        ofstream file1("Score.txt",ios::binary|ios::app);
        file1<<name<<endl;
        file1<<total<<endl;
        file1.close();
    }
};

//*************************************
//          instruction option
//*************************************
class Instruction
{
public:
    Instruction()
    {
        system("cls");
        //change color of instruction
        SetConsoleTextAttribute(colors,7);
        cout<<"\n\n\t\t\t\t\t\t\t\t\tInstructions\n";
        //change color of the tips
        SetConsoleTextAttribute(colors,13);
        cout<<R"(

                                              __________________________________________________________________
                                            / \                                                                 \.
                                           |   |    Here are some tips you might need to know before playing:\n  |.
                                            \__|                                                                 |.
                                               |   >>  This quiz is aimed to encourage you to check your general |.
                                               |       knowledge and improve your performance & confidence.which |.
                                               |       consist of 25 multiple choice  questions                  |.
                                               |                                                                 |.
                                               |                                                                 |.
                                               |   >>  quiz questions are arranged randomly on various topics    |.
                                               |       fit in to general knowledge, sport, music & art, maths,   |.
                                               |       science&technology                                        |.
                                               |                                                                 |.
                                               |                                                                 |.
                                               |   >>  Select==>                                                 |.
                                               |           Press only Valid Option--> (a,b,c,d)                  |.
                                               |                                                                 |.
                                               |   >>  Marks==>                                                  |.
                                               |           4 marks  will be awarded for each                     |.
                                               |                                                                 |.
                                               |                                                                 |.
                                               |                **********ALL THE BEST!***********"              |.
                                               |   ______________________________________________________________|___
                                               |  /                                                                 /.
                                               \_/_________________________________________________________________/.



                    )";
    }
};

//*****************************
//          Score
//*****************************
class Score
{
public:
    void Score1()
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t------------------ALL PLAYER RESULTS------------------ \n";
        SetConsoleTextAttribute(colors,5);
        gotoXY(65,10);
        cout<<"=====================\n";
        gotoXY(65,11);
        cout<<"  Name       Score"<<endl;
        gotoXY(65,12);
        cout<<"=====================\n\n";



        ifstream file2;
        file2.open("score.txt");
        while(file2>>name>>total)
        {
            cout<<"\t\t\t\t\t\t\t\t "<<name<<"\t\t"<<total<<"\n";
        }
        file2.close();
}
};

//*************************************
//            Exit 2
//*************************************
void exit()
{
    SetConsoleTextAttribute(colors,2);
    system("cls");
    gotoXY(17,15);
    cout<< R"(

                                 _____ _                 _                              ___                         _               _         _  _  _
                                /__   \ |__   __ _ _ __ | | __  _   _  ___  _   _      / __\___  _ __ ___   ___    /_\   __ _  __ _(_)_ __   / \/ \/ \
                                  / /\/ '_ \ / _` | '_ \| |/ / | | | |/ _ \| | | |    / /  / _ \| '_ ` _ \ / _ \  //_\\ / _` |/ _` | | '_ \ /  /  /  /
                                 / /  | | | | (_| | | | |   <  | |_| | (_) | |_| |_  / /__| (_) | | | | | |  __/ /  _  \ (_| | (_| | | | | /\_/\_/\_/
                                 \/   |_| |_|\__,_|_| |_|_|\_\  \__, |\___/ \__,_( ) \____/\___/|_| |_| |_|\___| \_/ \_/\__, |\__,_|_|_| |_\/ \/ \/
                                                                |___/            |/                                     |___/

    )";
    exit(0);
}

//*************************************
//      Options with choices(Menu)
//*************************************
void Menu()
{
    SetConsoleTextAttribute(colors,5);//Change color to offwhite
    //Displaying options
    cout<< R"(

                                                                                   MENU
                                                                               ____________
                                                                              |            |
                                                            0ooooooooooooooooo| [1] Play   |oooooooooooooooooo
                                                            0                 |____________|
                                                            0
                                                            0                  ____________
                                                            0                 |            |
                                                            0ooooooooooooooooo| [2] Score  |ooooooooooooooooo0
                                                                              |____________|                 0
                                                                                                             0
                                                                               ____________                  0
                                                                              |            |                 0
                                                            0ooooooooooooooooo| [3] Help   |ooooooooooooooooo0
                                                            0                 |____________|
                                                            0
                                                            0                   ___________
                                                            0                  |           |
                                                            0oooooooooooooooooo| [4] Exit  |oooooooooooooooooo
                                                                               |___________|



    )";

    SetConsoleTextAttribute(colors,7);//change the color to purple
    char choice;
    gotoXY(40,36);
    cout<<"Enter your choice[1-4]:--> ";
    gotoXY(73,39);
    cout<<"Press enter to continue... ";
    gotoXY(67,36);//move the  cursor up to the enter name
    cin>>choice;

    switch(choice)
    {
    case '1':
        {
            Play();
            Question();
            Result();
            HomeOrExit();
            break;
        }
    case '2':
        {
            Score S1;
            S1.Score1();
            HomeOrExit();
            break;
        }
    case '3':
        {
            Instruction();
            HomeOrExit();
            break;
        }
    case '4':
        {
            exit();
            break;
        }
    default:
        {
            cout<<"INVALID CHOICE";
            HomeOrExit();
        }
    }
}

int main()
{
    Display D1;
    D1.Display1();
    Menu();
    return 0;
}
