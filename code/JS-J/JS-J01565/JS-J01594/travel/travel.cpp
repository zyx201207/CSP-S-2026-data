#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
bool check(char c1,char c2) {
    bool flag1=0,flag2=0;
    if(c1=='A'||c1=='B'||c1=='C') flag1=1;
    if(c2=='A'||c2=='B'||c2=='C') flag2=1;
    return flag1==flag2;
}
int c1,c3;
string c2,c4,ans;
signed main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        ans+='1';
        int n2=(c2[0]-'0')*10+(c2[1]-'0');
        int n4=(c4[0]-'0')*10+(c4[1]-'0');
        if(n2==n4) {
            ans+='1';
            char h2=c2[2],h4=c4[2];
            if(check(h2,h4)) {
                ans+='1';
                if((int(h4)==int(h2+1)||int(h2)==(h4+1))) ans+='1';
                else ans+='0';
            }
            else ans+="00";
        }
        else ans+="000";
    } 
    else ans+="0000";
    cout<<ans<<'\n';
    return 0;
}