#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>, pair<int,int>);

int main () {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n, m;
    cin >> n >> m;

    vector<int>card;
    map<int, int>cnt;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
        cnt[tmp] = 0;
    }

    typedef vector<int>::size_type vint;
    for (int i = 0; i < n; i++) {
        vector<int>desktop;

        for (vint j = i; j < card.size(); j++) {
            desktop.push_back(card[j]);

            for (vint k = 0; k < desktop.size() - 1; k++) {
                if (desktop[k] == card[j]) {
                    do {
                        desktop.pop_back();
                    } while (desktop[desktop.size() - 1] == card[j]);

                    desktop.pop_back();

                    break;
                }
            }
        }

        for (vint j = 0; j < desktop.size(); j++) {
            cnt[desktop[j]]++;
        }
    }

    cout<<endl;

    vector<pair<int,int> >tmp;
    typedef map<int,int>::iterator mit;
    for (mit it = cnt.begin(); it != cnt.end(); it++) {
        tmp.push_back(*it);
    }

    sort(tmp.begin(), tmp.end(), cmp);

    typedef vector<pair<int, int> >::size_type viint;
    for (viint i = 0; i < tmp.size(); i++) {
        cout << tmp[i].second << ' ';
    }

    cout << endl;

    return 0;
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}
