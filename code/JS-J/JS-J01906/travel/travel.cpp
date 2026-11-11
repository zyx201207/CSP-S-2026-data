#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string c1, s1, c2, s2;
ll x11, y11, x22, y22;
void init(){
    c1[0] -= '0';
    c1[1] -= '0';
    c2[0] -= '0';
    c2[1] -= '0'; 
    x11 = c1[0] * 10 + c1[1], y11 = c2[0] * 10 + c2[1];
    //
    s1[0] -= '0';
    s1[1] -= '0';
    s2[0] -= '0';
    s2[1] -= '0';
    x22 = s1[0] * 10 + s1[1], y22 = s2[0] * 10 + s2[1];
}
bool solve1(){
    if (x11 == y11) return 1;
    return 0;
}
bool solve2(){
    if (x22 == y22) return 1;
    return 0;
}
bool solve3(){
    char ch1 = s1[2], ch2 = s2[2];
    if (ch1 == 'A' && ch2 == 'B') return 1;
    if (ch1 == 'A' && ch2 == 'C') return 1;
    if (ch1 == 'C' && ch2 == 'B') return 1;
    if (ch2 == 'A' && ch1 == 'B') return 1;
    if (ch2 == 'A' && ch1 == 'C') return 1;
    if (ch2 == 'C' && ch1 == 'B') return 1;
    if (ch1 == 'D' && ch2 == 'E') return 1;
    if (ch2 == 'D' && ch1 == 'E') return 1;
    return 0;
}
bool solve4(){
    char ch1 = s1[2], ch2 = s2[2];
    if (ch1 == 'D' && ch2 == 'E') return 1;
    if (ch2 == 'D' && ch1 == 'E') return 1;
    if (ch2 == 'A' && ch1 == 'B') return 1;
    if (ch1 == 'A' && ch2 == 'B') return 1;
    if (ch1 == 'B' && ch2 == 'C') return 1;
    if (ch2 == 'B' && ch1 == 'C') return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    init();
    ll ans1 = solve1(), ans2, ans3, ans4;
    if (ans1 == 1){
        ans2 = solve2();
        if (ans2 == 1){
            ans3 = solve3();
            if (ans3 == 1){
                ans4 = solve4();
                cout << ans1 << ans2 << ans3 << ans4 << endl;
            }
            else cout << "1100" << endl;
        }
        else cout << "1000" << endl;
    }
    else cout << "0000" << endl;
    return 0;
}
//