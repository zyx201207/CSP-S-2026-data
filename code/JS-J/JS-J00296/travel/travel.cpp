#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int MAXN=200005;
string c1,c2,s1,s2;
bool f=0;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((s1[2]-'A'<=2 && s2[2]-'A'<=2)||(s1[2]-'A'>=3 && s2[2]-'A'>=3)) f=1,cout<<1;
    else cout<<0;
    if(f==1 && abs(s1[2]-s2[2])==1) cout<<1;
    else cout<<0;
    return 0;
}

//id:JS-J00296
//This is the code of travel.
//100 pts
//All samples correct.
//Last modified on Oct.31st 08:46
//password:Trick||Treat!
