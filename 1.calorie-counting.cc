#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int res{};
    string line;
    vector<int> cals;

    while(getline(cin, line)) {
        int totalCal{};
        while(!line.empty()) {
            istringstream iss{line};
            int cal;
            if(iss >> cal)
                totalCal += cal;
            getline(cin, line);
        }
        cals.push_back(totalCal);
    }
    sort(cals.begin(), cals.end());

    for(int i = cals.size() - 1, cnt = 0; i >= 0 and cnt < 3; --i, ++cnt)
        res += cals[i];

    cout << res << endl;
}
