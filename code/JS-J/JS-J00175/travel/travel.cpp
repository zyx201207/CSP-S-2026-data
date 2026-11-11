#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a!=c)cout<<"0000";
    else if(b[1]!=d[1]||b[0]!=d[0])cout<<"1000";
    else if((b[2]>'C'&&d[2]<='C')||(b[2]<='C'&&d[2]>'C'))cout<<"1100";
    else if(((abs(b[2]-d[2])!=1)&&!((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')))||(b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C'))cout<<"1110";
    else cout<<"1111";
    return 0;
}
