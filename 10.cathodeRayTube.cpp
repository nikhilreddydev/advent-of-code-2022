#include<iostream>
#include<string>
#include<sstream>
#include<unordered_set>
using namespace std;

int main(){
    string instruction;
    int x{1};
    int cycle{};

    while(getline(cin, instruction)) {
        istringstream iss{instruction};

        string opcode;
        int operand;

        iss >> opcode;

        if(opcode == "noop") {
            cycle++;
            if(cycle == x || cycle == x + 1 || cycle == x + 2)
                cout << '#';
            else
                cout << '.';

            if(cycle % 40 == 0) {
                cout << endl;
                x += 40;
            }
        } else {
            int operand;
            iss >> operand;

            int countDown{2};
            while(countDown--) {
                cycle++;
                if(cycle == x || cycle == x + 1 || cycle == x + 2)
                    cout << '#';
                else
                    cout << '.';

                if(cycle % 40 == 0) {
                    cout << endl;
                    x += 40;
                }

                if(!countDown) {
                    x += operand;
                    // cout << cycle << " " << x << endl;
                }
            }
        }
    }
}
