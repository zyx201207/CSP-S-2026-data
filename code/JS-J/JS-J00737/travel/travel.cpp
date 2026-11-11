#include<bits/stdc++.h>
using namespace std;
bool ans1,ans2,ans3,ans4;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    ans1=(a==c);
    ans2=(ans1&&(b[0]==d[0])&&(b[1]==d[1]));
    ans3=((ans2&&(b[2]<='C'&&d[2]<='C'))||(ans2&&(b[2]>='D'&&d[2]>='D')));
    if(b[2]=='A') ans4=(ans3&&d[2]=='B');
    else if(b[2]=='B') ans4=(ans3&&(d[2]=='A'))||(ans3&&(d[2]=='C'));
    else if(b[2]=='C') ans4=(ans3&&(d[2]=='B'));
    else if(b[2]=='D') ans4=(ans3&&(d[1]=='F'));
    else if(b[2]=='F') ans4=(ans3&&(d[1]=='D'));
    cout<<int(ans1)<<int(ans2)<<int(ans3)<<int(ans4);
    return 0;
}
