#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char s[5],y[5],d[5],x[5];
    cin>>s>>y>>d>>x;
    if(s[0]==d[0]&&s[1]==d[1])
        if(y[0]==x[0]&&y[1]==x[1])
            if(y[2]=='A'&&x[2]=='B')
                cout<<"1111";
            else if(y[2]=='C'&&x[2]=='B')
                cout<<"1111";
            else if(y[2]=='E'&&x[2]=='F')
                cout<<"1111";
            else if(y[2]=='A'&&x[2]=='C')
                cout<<"1110";
            else cout<<"1100";
        else cout<<"1000";
    else cout<<"0000";
    return 0;
}
