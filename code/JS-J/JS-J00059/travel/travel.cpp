#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5 + 10 , INF = 1e18 , mod = 1e9 + 7;
bool check(string s1 , string s2){
    if(s1[2] == 'A' && s2[2] == 'B') return 1;
    if(s1[2] == 'A' && s2[2] == 'C') return 1;
    if(s1[2] == 'B' && s2[2] == 'A') return 1;
    if(s1[2] == 'B' && s2[2] == 'C') return 1;
    if(s1[2] == 'C' && s2[2] == 'A') return 1;
    if(s1[2] == 'C' && s2[2] == 'B') return 1;
    if(s1[2] == 'D' && s2[2] == 'F') return 1;
    if(s1[2] == 'F' && s1[2] == 'D') return 1;
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    int c1 , c2;
    string s1 , s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2){
        cout<<"1";
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout<<"1";
            if(check(s1 , s2)){
                cout<<"1";
                if(s1[2] == 'A' && s2[2] == 'C') cout<<"0";
                else if(s1[2] == 'C' && s2[2] == 'A') cout<<"0";
                else cout<<"1";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else cout<<"0000";
    return 0;
}
