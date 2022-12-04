#include<iostream>
#include<vector>

using namespace std;

// A, X are rock 1
// B, Y are paper 2
// C, Z are scissor 3
int getScore(char op, char u) {
    if(op == 'A') {
        if(u == 'X')
            return 3 + 0;
        else if(u == 'Y')
            return 1 + 3;
        else
            return 2 + 6;
    } else if(op == 'B') {
        if(u == 'X')
            return 1 + 0;
        else if(u == 'Y')
            return 2 + 3;
        else
            return 3 + 6;
    } else {
        if(u == 'X')
            return 2 + 0;
        else if(u == 'Y')
            return 3 + 3;
        else
            return 1 + 6;
    }
}

int main() {
    char op, u;

    int yourScore{};
    while(cin >> op) {
        cin >> u;
        yourScore += getScore(op, u);
    }

    cout << yourScore << endl;
}
