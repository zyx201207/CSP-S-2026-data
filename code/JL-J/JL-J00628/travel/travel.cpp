#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int ans,sum;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if(b[2]=='D'||b[2]=='F'){
                if(d[2]=='D'||d[2]=='F'){
                    cout<<1<<1;
                }
                else cout<<0<<0;
            }
            else if(d[2]=='D'||d[2]=='F') cout<<0<<0;
            else {
                cout<<1;
                if(d[2]=='B'||b[2]=='B') cout<<1;
                else cout<<0;
            }
        }else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}









