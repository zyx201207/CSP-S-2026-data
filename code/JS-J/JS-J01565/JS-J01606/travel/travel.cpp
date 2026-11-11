#include <bits/stdc++.h>
using namespace std;
#define int long long
//final
signed main () {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool flag=false;
    if (c1==c2) {
        cout<<1;
        flag=true;
    } else{
        cout<<0;
    }
    bool flag1=false;
    if (flag==true&&s1[0]==s2[0]&&s1[1]==s2[1]) {
        cout<<1;
        flag1=true;
    } else {
        cout<<0;
    }
    bool flag2=false;
    if ((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')) flag2=true;
    bool flag3=false;
    if (flag1==true&&flag2==true) {
        cout<<1;
        flag3=true;
    } else{
        cout<<0;
    }
    if ((flag3==true)&&(abs(s1[2]-s2[2])==1)) cout<<1;
    else cout<<0;
    return 0;
}
