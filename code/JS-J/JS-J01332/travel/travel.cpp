#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a=="01"||a=="16"||c=="01"||c=="16"){
        cout<<"0000";
        return 0;
    }
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if(b[2]<'D'&&d[2]<'D'){
                cout<<1;
                if(b[2]=='B'||d[2]=='B'){
                    cout<<1;
                }
                else cout<<0;
            }
            else if(b[2]>'C'&&d[2]>'C'){
                cout<<11;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else{
        cout<<"0000";
    }
    return 0;
}
