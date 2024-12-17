#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

struct Question {
    string question;
    string options[4];
    int correctAnswer; // Index of the correct option (0-3)
};

void displayQuestion(const Question& q, int number) {
    cout << "Q" << number << ": " << q.question << endl;
    for (int i = 0; i < 4; ++i) {
        cout << char('A' + i) << ". " << q.options[i] << endl;
    }
    cout << "Your Answer (A/B/C/D): ";
}

int main() {
   
    Question questions[] = {
        {"What is the size of an int in C++?", {"2 bytes", "4 bytes", "8 bytes", "Depends on the system"}, 1},
        {"Which keyword is used to define a constant in C++?", {"const", "define", "static", "final"}, 0},
        {"Which loop is used when the number of iterations is unknown?", {"for", "while", "do-while", "goto"}, 1},
        {"What is the purpose of a destructor in C++?", {"Initialize data", "Release resources", "Create objects", "Throw exceptions"}, 1},
        {"Which operator is used for pointer dereferencing in C++?", {"*", "&", "@", "%"}, 0},
        {"What is the output of the following code: `cout << 5 / 2;`?", {"2", "3", "2.5", "Error"}, 0},
        {"What does the 'new' keyword do in C++?", {"Allocates memory dynamically", "Creates an array", "Creates an object", "None of the above"}, 0},
        {"What is the purpose of a constructor in C++?", {"To initialize objects", "To destroy objects", "To copy objects", "To assign values to objects"}, 0},
        {"Which function is used to get the size of a variable in C++?", {"sizeof()", "length()", "size()", "count()"}, 0},
        {"What is the default value of an uninitialized local variable in C++?", {"Undefined", "Zero", "Null", "Garbage value"}, 0}
    };

    srand(time(0)); 
    set<int> usedIndexes; 
    int totalQuestions = 5; 
    int score = 0;

    cout << "Welcome to the Quiz Game!" << endl;

    // Ask 5 random questions
    for (int i = 0; i < totalQuestions; ++i) {
        int index;
        do {
            index = rand() % 10; // Randomly select a question (0-9)
        } while (usedIndexes.count(index)); // Ensure no repetition
        usedIndexes.insert(index);

        displayQuestion(questions[index], i + 1);

        char answer;
        cin >> answer;
        int answerIndex = toupper(answer) - 'A';

        if (answerIndex == questions[index].correctAnswer) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer is: "
                 << char('A' + questions[index].correctAnswer) << endl;
        }
        cout << endl;
    }

    cout << "Quiz Over! Your final score is: " << score << "/" << totalQuestions << endl;

    return 0;
}
