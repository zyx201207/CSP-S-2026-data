#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
void solve(){
    string c1,s1,c2,s2; cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            bool a = (s1[2] == 'D' || s1[2] == 'F');
            bool b = (s2[2] == 'D' || s2[2] == 'F');
            if(a == b){
                if(s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'C') cout << "1111";
                else cout << "1110";
            }else cout << "1100";
        }else cout << "1000";
    }else cout << "0000";
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tid,T = 1;
    while(T--) solve();
}

// expect 100 pts