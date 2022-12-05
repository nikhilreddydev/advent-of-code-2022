#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

int main() {
    string line;
    vector<string> v;
    getline(cin, line);

    while(!line.empty()) {
        v.push_back(line);
        getline(cin, line);
    }

    istringstream iss{v.back()};
    int stackCount{};
    while(iss >> stackCount);

    vector<stack<char>> stacks(stackCount);
    v.pop_back();

    for(int li = v.size() - 1; li >= 0; --li) {
        for(int stInd = 0, j = 1; stInd < stackCount; j += 4, ++stInd)
            if(v[li][j] != ' ')
                stacks[stInd].push(v[li][j]);
    }

    string move, from, to;
    int mi, fi, ti;

    while(getline(cin, line)) {
        istringstream iss{line};
        iss >> move >> mi >> from >> fi >> to >> ti;

        stack<char> tmp;
        for(int i = 0; i < mi; ++i) {
            tmp.push(stacks[fi - 1].top());
            stacks[fi - 1].pop();
        }

        while(!tmp.empty()) {
            stacks[ti - 1].push(tmp.top());
            tmp.pop();
        }
    }

    for(auto &st: stacks)
        cout << st.top();
    cout << endl;
}
