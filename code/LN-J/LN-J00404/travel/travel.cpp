#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=s1[2]-'A',b=s2[2]-'A';
    if(c1==c2) cout<<1;
    else cout<<0;
    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else cout<<0;
    if((a<=2&&b<=2)||(a>2&&b>2)) cout<<1;
    else cout<<0;
    if((a==0&&b==1)||(a==1&&b==0)||(a==1&&b==2)||(a==2&&b==1)||(a==3&&b==4)||(a==4&&b==3)) cout<<1;
    else cout<<0;
    return 0;
}
