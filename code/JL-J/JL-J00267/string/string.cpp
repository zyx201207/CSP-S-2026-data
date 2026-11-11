#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
/*struct ltts{
    int n;
    char c;
    int use;
};
vector<ltts> a;*/
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out","w", stdout);
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int x; char y;
        cin >> x >> y;
        n += x * 1LL;
        for(int j = 0; j < x; j++) s += y;
    }
    int ans = 0;
    for(int i = 0; i < (n + 1) / 2; i++){
        if(s[i] != s[n - i - 1]) ans++;
    }
    cout << ans << endl;
    return 0;
}