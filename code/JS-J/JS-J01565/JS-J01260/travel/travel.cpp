#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,cp,s,sp;
    cin>>c>>cp>>s>>sp;
    if(c==s){
        cout<<1;
        if(cp[0]==sp[0]&&cp[1]==sp[1]){
            cout<<1;
            if((cp[2]<='C'&&sp[2]<='C')||(cp[2]>'C'&&sp[2]>'C')){
                cout<<1;
                if(!(cp[2]<='C'&&cp[2]!='B'&&sp[2]!='B')){
                    cout<<1;
                    return 0;
                }cout<<0;
                return 0;
            }cout<<0<<0;
            return 0;
        }cout<<0<<0<<0;
        return 0;
    }cout<<0<<0<<0<<0;
    return 0;
}
