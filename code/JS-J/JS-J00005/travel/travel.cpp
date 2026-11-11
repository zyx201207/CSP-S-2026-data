#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0] && b[1]==d[1]){
            cout<<1;
            char x=b[2],y=d[2];
            if((x=='D' && y!='F') || (x=='F' && y!='D') || (x!='F' && y=='D') || (x!='D' && y=='F')) cout<<"00";
            else{
                cout<<1;
                if(y=='F') y='E';
                if(x+1==y || y+1==x) cout<<1;
                else cout<<0;
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
