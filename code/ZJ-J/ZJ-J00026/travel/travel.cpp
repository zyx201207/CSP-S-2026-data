//done
/*
today is the day the mouz fight the bee
mouz will win
i love cs2
--8:40
died
--11:53
last re-check
--11:56
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
    bool f1=0,f2=0,f3=0,f4=0;
    if(c1==c2)f1=1;
    if(f1&&s1.substr(0,2)==s2.substr(0,2))f2=1;
    char a=s1.back(),b=s2.back();
    if(f2&&((a<='C'&&b<='C')||(a>='D'&&b>='D')))f3=1;
    if(f3&&(a==b-1||b==a-1))f4=1;
    cout<<f1<<f2<<f3<<f4<<'\n';
}