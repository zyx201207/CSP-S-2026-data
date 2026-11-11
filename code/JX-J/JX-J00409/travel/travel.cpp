#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x>>b>>y;
    if((a[0]==b[0])&&(a[1]==b[1])){
        cout<<1;
        if(x[0]==y[0]&&x[1]==y[1]){
            cout<<1;
            if((x[2]<='C')==(y[2]<='C')){
                cout<<1;
                if(abs((x[2]-'A')-(y[2]-'A'))==1){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
}
