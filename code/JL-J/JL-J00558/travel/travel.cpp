#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
    if(c==cc){
        cout<<1;
        if(s[0]==ss[0]&&s[1]==ss[1]){
            cout<<1;
            int a=0,b=0;
            if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
                a=1;
            }else if(s[2]=='D'||s[2]=='F'){
                a=2;
            }
            if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'){
                b=1;
            }else if(ss[2]=='D'||ss[2]=='F'){
                b=2;
            }
            if(a==b){
                cout<<1;
                bool f=(s[2]=='A'&&ss[2]=='B');
                bool ff=(s[2]=='B'&&(ss[2]=='A'||ss[2]=='C'));
                bool fff=(s[2]=='C'&&ss[2]=='B');
                bool ffff=(s[2]=='D'&&ss[2]=='F');
                bool fffff=(s[2]=='F'&&ss[2]=='D');
                if(f||ff||fff||ffff||fffff){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
