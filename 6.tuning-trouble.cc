#include<iostream>
#include<string>

using namespace std;

bool all_diff(int i, string &line) {
    for(int k = i - 13; k <= i; ++k)
        for(int j = k + 1; j <= i; ++j)
            if(line[k] == line[j])
                return false;
    return true;
}

int main() {
    string line;
    getline(cin, line);

    for(int i = 13; i < line.size(); ++i)
        if(all_diff(i, line)) {
            cout << i + 1 << endl;
            exit(0);
        }

    exit(1);
}
