#include<bits/stdc++.h>
#define int long long
using namespace std;
string c,s,cc,ss;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    // travel
    cin>>c>>s>>cc>>ss;// c 是车箱号，s 是座位号
    if(c==cc){
        cout<<1;
    }else cout<<0;

    if(s==ss){
        cout<<"000";
        return 0;
    }
        if(s.substr(0,2)==ss.substr(0,2)){
            cout<<1;
        }else cout<<0;

        if(s.substr(0,2)==ss.substr(0,2)){
            if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'))||((s[2]=='D'||s[2]=='E')&&(ss[2]=='D'||ss[2]=='E'))){
                cout<<1;
            }else cout<<0;
        }else cout<<0;

        if(c==cc){
            if(s.substr(0,2)==ss.substr(0,2)){
                if((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='B'&&ss[2]=='C'||(s[2]=='C'&&ss[2]=='B')||(s[2]=='D'&&ss[2]=='E')||(s[2]=='E'&&ss[2]=='D'))){
                    cout<<1;
                }else cout<<0;
            }else cout<<0;
        }else cout<<0;

    return 0;
}
