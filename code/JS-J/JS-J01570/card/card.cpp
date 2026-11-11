#include<bits/stdc++.h>
using namespace std;

int cnt[300005];
int p[500005];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;

    for (int i = 1;i <= n;i++) {
        cin >> p[i];
    }

    for (int i = 1;i <= n;i++) {
        string s = "";
        for (int j = i;j <= n;j++) {
            if (s.find((p[j]+'0')) == -1) {
                s += p[j]+'0';
            } else {
                s = s.substr(0,s.find((p[j]+'0')));
                s += p[j]+'0';
            }
        }
        for (int j = 0;j < s.size();j++) {
            cnt[s[j]-'0']++;
        }
    }

    for (int i = 1;i <= m;i++) {
        cout << cnt[i] << ' ';
    }
    cout << endl;
    return 0;
}
