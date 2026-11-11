#include<bits/stdc++.h>
using namespace std;
int a,b,d,e;
char c,f;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d>>e>>f;
    if(a!=d) cout<<"0000";
    else{
        cout<<'1';
        if(b!=e) cout<<"000";
        else{
            cout<<'1';
            if(c<'D'&&f<'D') cout<<'1';
            else if(c>'C'&&f>'C') cout<<'1';
            else cout<<'0';
            if(c+'1'==f||c-'f'==c||c!='C'&&f!='D') cout<<'1';
            else cout<<'0';
            }
        }
    return 0;
}
