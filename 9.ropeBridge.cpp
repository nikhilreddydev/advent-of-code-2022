#include<iostream>
#include<set>
#include<utility>
#include<string>
#include<sstream>
#include<cassert>
#include<vector>

using namespace std;

void updateTail(const pair<int, int> &head, pair<int, int> &tail) {
    int hr = head.first, hc = head.second;
    int &tr = tail.first, &tc = tail.second;

    if(abs(hr - tr) > 1 || abs(hc - tc) > 1) {
        if(tc == hc) {
            // move vertically
            tr += hr > tr ? 1 : -1;
        } else if(hr == tr) {
            // move horizontally
            tc += hc > tc ? 1 : -1;
        } else {
            if(hr < tr and hc < tc) {
                // move top-left
                --tr, --tc;
            } else if(hr < tr and hc > tc) {
                // move top-right
                --tr, ++tc;
            } else if(hr > tr and hc > tc) {
                ++tr, ++tc;
            } else {
                ++tr, --tc;
            }
        }
    }
}

int main() {
    string command;
    set<pair<int, int>> tailPositions;

    pair<int, int> head;

    vector<pair<int, int>> tails(9);

    while(getline(cin, command)) {
        istringstream iss{command};
        string dir;
        int steps{};

        iss >> dir >> steps;

        if(dir == "U") {
            while(steps--) {
                --head.first;
                updateTail(head, tails[0]);
                for(int i = 1; i < 9; ++i)
                    updateTail(tails[i - 1], tails[i]);
                tailPositions.insert(tails[8]);
            }
        } else if(dir == "R") {
            while(steps--) {
                ++head.second;
                updateTail(head, tails[0]);
                for(int i = 1; i < 9; ++i)
                    updateTail(tails[i - 1], tails[i]);
                tailPositions.insert(tails[8]);
            }
        } else if(dir == "D") {
            while(steps--) {
                ++head.first;
                updateTail(head, tails[0]);
                for(int i = 1; i < 9; ++i)
                    updateTail(tails[i - 1], tails[i]);
                tailPositions.insert(tails[8]);
            }
        } else {
            while(steps--) {
                --head.second;
                updateTail(head, tails[0]);
                for(int i = 1; i < 9; ++i)
                    updateTail(tails[i - 1], tails[i]);
                tailPositions.insert(tails[8]);
            }
        }

    }

    cout << tailPositions.size() << endl;
}
