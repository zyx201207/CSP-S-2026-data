#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a; i <= b; i++)
#define For2(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N  = 1e6 + 5;
inline int read() {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {x = x * 10 + c - '0';c = getchar();}
    return x;
}

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    map<char,int> mp; mp['A'] = 1; mp['B'] = 1,mp['C'] = 1; mp['D'] = 2; mp['F'] = 2;
    string c1,s1,c2,s2; cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) cout << "0000";
    else {
        cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << 1;
            if (mp[s1[2]] == mp[s2[2]]) {
                cout << 1;
                char a = s1[2],b = s2[2];
                if (a > b) swap(a,b);
                if (a == 'A' && b == 'B') cout << 1;
                else if (a == 'B' && b == 'C') cout << 1;
                else if (a == 'D' && b == 'F') cout << 1;
                else cout << 0;
            }else cout << "00";
        }else cout << "000";
    }
    return 0;
}
