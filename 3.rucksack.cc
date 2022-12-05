#include<iostream>
#include<string>

using namespace std;

int main() {
    int res{};
    string rack, rack1, rack2, mistake;

    while(cin >> rack) {
        char mistake;

        cin >> rack1 >> rack2;
        int l1 = rack.size(), l2 = rack1.size(), l3 = rack2.size();

        for(int i = 0; i < l1; ++i) {
            for(int j = 0; j < l2; ++j)
                for(int k = 0; k < l3; ++k)
                    if(rack[i] == rack1[j] and rack1[j] == rack2[k]) {
                        mistake = rack[i];
                        goto got;
                    }
        }

got:    if(islower(mistake))
            res += mistake - 'a' + 1;
        else
            res += mistake - 'A' + 27;
    }

    cout << res << endl;
}
