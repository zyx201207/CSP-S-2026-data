#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c,b,d;
    cin>>a>>b>>c>>d;
    bool flag1=0,flag2=0;
    if(b[2]=='D'||b[2]=='F') flag1=1;
    if(d[2]=='D'||d[2]=='F') flag2=1;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if(flag1==flag2){
                cout<<1;
                if(flag1&&flag2 || abs(b[2]-d[2])==1&&!flag1&&!flag2){
                    cout<<1;
                }else{
                    cout<<0;
                    return 0;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
