// mathGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<math.h>
#include<cstdlib>

using namespace std;





enum enLevel{Easy=1,Medium=2,Hard=3,Mix=4};


enum enOperation {Add=1,Sub=2,Mul=3,Div=4,MixOp=5};

enum enAnswer{correct=1,wrong=2};


int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}
int readHowManyTimes(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;
    } while (number <= 0 || number > 10);
    return number;
}

struct stGameResult {
    int QueCount = 0;
    enLevel QueLevel;
    enOperation OpType;
    short CorrectAnswers = 0;
    short WrongAnswers = 0;
    enAnswer answer;
   
};

enLevel readQuestionLevel() {
    short level = 0;
    do {
       cout<<("Enter Question Level [1] Easy , [2] Medium, [3] Hard, [4] Mix  ");
       cin >> level;
    } while (level < 1 || level > 4);
   
    return (enLevel)level;
}

enOperation readOpType() {
    short type = 0;
    do {
        cout << ("Enter Question Type [1] Add , [2] Sub, [3] Mul, [4] div, [5] Mix  ");
        cin >> type;
    } while (type < 1 || type >5);
    return (enOperation)type;
}

bool findIfPassOrFail(short right, short wrong) {
    return right >= wrong;
}
void gameLogic(enOperation operation,int rand1,int rand2 ,short& correctAnswer,short& wrongAnswer) {
    int answer = 0;
    switch (operation) {
    case enOperation::Add: {
        cout << rand1 << endl;
        cout << rand2 << " + " << endl;
        cout << "___________________" << endl;    
        cin >> answer;
        if (answer == rand1 + rand2) {
            cout << "Right answer " << endl;
            cout << endl;
            correctAnswer++;
        }
        else {
            cout<<"Wrong, answer is "<< rand1 + rand2 << endl;
            cout << endl;
            wrongAnswer++;
        }
        break;
    }
    case enOperation::Sub: {
        cout << rand1 << endl;
        cout<< rand2<< " - " << endl;
        cout << "___________________"<<endl;
        cin >> answer;
        if (answer == rand1 - rand2) {
            cout << "Right answer " << endl;
            cout << endl;
            correctAnswer++;
        }
        else {
            cout << "Wrong, answer is " << rand1 - rand2 << endl;
            cout << endl;
            wrongAnswer++;

        }
        break;
    }
    case enOperation::Div: {
        cout << rand1 << endl;
        cout << rand2 << " / " << endl;
        cout << "___________________" << endl;        cin >> answer;
        if (answer == rand1 / rand2) {
            cout << "Right answer " << endl;
            cout << endl;
            correctAnswer++;
        }
        else {
            cout << "Wrong, answer is " << rand1 / rand2 << endl;
            cout << endl;
            wrongAnswer++;

        }
        break;
    }
    case enOperation::Mul: {
        cout << rand1 << endl;
        cout << rand2 << " * " << endl;
        cout << "___________________" << endl;        cin >> answer;
        if (answer == rand1 - rand2) {
            cout << "Right answer "  << endl;
            cout << endl;
            correctAnswer++;

        }
        else {
            cout << "Wrong, answer is " << rand1 * rand2 << endl;
            cout << endl;
            wrongAnswer++;

        }
        break;
    }
    }
}

string printOperationName(enOperation name) {
    string operationName[5]{ "Add" , "Sub", "Mul", "div"," Mix" };
    return operationName[name - 1];
}
string printLevelName(enLevel name) {
    string levelNames[4]{ "Easy ","Medium","Hard ","Mix " };
    return levelNames[name - 1];
}




int generateNumbers(enLevel level) {

    if (enLevel::Easy == level) {
        return randomNumber(1, 10);
    }
    else if (enLevel::Medium == level) {
     return   randomNumber(10, 30);
    }
    else if (enLevel::Hard) {
      return   randomNumber(50, 100);
    }
   

}

enAnswer RightOrWrongAnswer(int correct, int wrong) {
    if (correct > wrong) {
        return enAnswer::correct;
    }
    return enAnswer::wrong;
}

void chaingeColor(enAnswer answer) {
    switch (answer) {
    case enAnswer::wrong: {
        system("color 4F");
        cout << "\a";
        break;
    }
    case enAnswer::correct: {
        system("color 2F");
        break;
    }
    default:
        system("color 0F");
        break;
    }
}

void clearScreen() {
    system("color 0F");
    system("cls");
}


stGameResult playGame(short roundsToPlay,short &correctAnswer,short& WrongAnswer) {
    enLevel level = readQuestionLevel();
    enLevel levelOption = level;
    enOperation type = readOpType();
    enOperation opType = type;
    cout << endl;
    for (int i = 0; i < roundsToPlay; i++) {
        if (type == 5) {
            opType = (enOperation)randomNumber(1, 4);
        }
        if (level == enLevel::Mix) {
            levelOption = (enLevel)randomNumber(1, 4);
        }
        cout << "Question [" <<i+1<<" / "<<roundsToPlay << "]"<< endl;
        gameLogic(opType, generateNumbers(levelOption), generateNumbers(levelOption),correctAnswer,WrongAnswer);
        chaingeColor(RightOrWrongAnswer(correctAnswer, WrongAnswer));
     
    }
  

    return { roundsToPlay ,levelOption,opType,correctAnswer,WrongAnswer };

     
       

}

void showGameOver() {

    cout << "\t\t\t----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t+++GAME OVER+++" << endl;
    cout << endl;
    cout << "\t\t\t----------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;


}

char readPlayAgainFun(string message) {
    char answer = ' ';
    do {
        cout << message << endl;
        cin >> answer;

    } while (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N');
    return answer;

}


void startGame(short &correctAnswer,short &wrongAnswer){
    char playAgain = ' ';
    do {

    
    short RoundsToPlay = readHowManyTimes("How many questions you want to answer ");
    stGameResult info;
    info = playGame(RoundsToPlay,correctAnswer, wrongAnswer);
    string result = "";
    if (findIfPassOrFail(correctAnswer, wrongAnswer)) {
        result = "Pass";
    }
    else {
        result = "Fail";
    }
  cout << "--------------------------------------------------" << endl;
  cout << endl;
  cout << "\t\t\t final result is   " << result << endl;
  cout << "--------------------------------------------------" << endl;
  cout << "Number of questions     : " << info.QueCount << endl;
  cout << "Question Level          : " << printLevelName( info.QueLevel) << endl;
  cout << "OpType                  : " << printOperationName(info.OpType) << endl;
  cout << "Number of Right Answers : " << info.CorrectAnswers << endl;
  cout << "Number of wronge answers: " << info.WrongAnswers << endl;
  cout << "--------------------------------------------------" << endl;
  showGameOver();
  playAgain = readPlayAgainFun(" Do you want to play again Y/N");

    } while (playAgain != 'N' && playAgain != 'n');
}

int main()
{
    srand((unsigned)time(NULL));
    short correctAnswer = 0;
    short wrongAnswer = 0;
   
    startGame(correctAnswer, wrongAnswer);

}
