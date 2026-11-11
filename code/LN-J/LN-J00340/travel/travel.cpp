#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool flag=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2);
    cout<<(s1[0]==s2[0]&&s1[1]==s2[1]);
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
        cout<<1;
        flag=true;
    } else cout<<0;
    cout<<(flag&&(s1[2]+1==s2[2]||s1[2]-1==s2[2]));
    return 0;
}
