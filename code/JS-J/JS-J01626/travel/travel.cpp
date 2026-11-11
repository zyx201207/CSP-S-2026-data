#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        //cout<<b[1]<<" "<<c[1];
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            int x=0;
            int y=0;
            if(b[2]=='D'||b[2]=='F') x=1;
            if(d[2]=='D'||d[2]=='F') y=1;
            if(x==y){
                cout<<1;
                if(b[2]-1==d[2]||b[2]+1==d[2]) cout<<1;
                else cout<<0;
            }
            else{
                cout<<0;
                cout<<0;
            }
        }
        else{
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else{
       cout<<0;
       cout<<0;
       cout<<0;
       cout<<0;
    }
    return 0;
}
