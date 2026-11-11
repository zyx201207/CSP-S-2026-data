#include<bits/stdc++.h>
using namespace std;
string s,x;
int a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s>>b>>x;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    else if(a==b){
        cout<<1;
        if(s[0]==x[0]&&s[1]==x[1]){
            cout<<1;
            if((s[2]>'C'&&x[2]>'C')||(s[2]<='C'&&x[2]<='C')){
                cout<<1;
                if(x[2]-1==s[2]||s[2]-1==x[2]){
                    cout<<1;
                    return 0;
                }
                cout<<"0";
                return 0;
            }
            cout<<"00";
            return 0;
        }
        cout<<"000";
        return 0;
    }
    return 0;
}
