#include<iostream>
#include<string>

using namespace std;

bool isOverlap(string &pair) {
    auto comma = pair.find(",");
    string s1 = pair.substr(0, comma);
    string s2 = pair.substr(comma + 1);

    auto dash = s1.find("-");
    int l1 = stoi(s1.substr(0, dash));
    int r1 = stoi(s1.substr(dash + 1));

    dash = s2.find("-");
    int l2 = stoi(s2.substr(0, dash));
    int r2 = stoi(s2.substr(dash + 1));

    return !(r1 < l2 or r2 < l1);
}

int main() {
    string pair;
    int res{};
    while(cin >> pair) {
        res += isOverlap(pair);
    }

    cout << res << endl;
}
