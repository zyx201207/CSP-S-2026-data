#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){cout<<"0000";return 0;}
    if(s1.substr(0,2)!=s2.substr(0,2)){cout<<"1000";return 0;}
    char p1=s1[2];char p2=s2[2];
    if(!(('A'<=p1&&p1<='C'&&'A'<=p2&&p2<='C')||('D'<=p1&&p1<='E'&&'D'<=p2&&p2<='E'))){
       cout<<"1100";
       return 0;
    }
    if(abs(p1-p2)!=1){cout<<"1110";return 0;}
    cout<<"1111";
    return 0;
}
