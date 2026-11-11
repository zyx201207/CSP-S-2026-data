#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
int sum;
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        sum ++;
        cout << 1;
    }
    else cout << 0;

    if (sum == 1 && s1[0] == s2[0] && s1[1] == s2[1]){
        sum ++;
        cout << 1;
    }
    else cout << 0;

    if (sum == 2 && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))){
        sum ++;
        cout << 1;
    }
    else cout << 0;

    if (sum == 3 && abs((s1[2] - 'A') - (s2[2] - 'A')) == 1){
        cout << 1;
    }
    else cout << 0;

    return 0;
}
