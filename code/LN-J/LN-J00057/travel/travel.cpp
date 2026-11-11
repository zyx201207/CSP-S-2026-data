#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
char e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>e>>c>>d>>f;
    if(a!=c){cout<<"0000";return 0;}
    else{
        cout<<1;
        if(b!=d){cout<<"000";return 0;}
        else{
            cout<<1;
            if(e=='F'&&f=='D'||e=='D'&&f=='F'||e=='A'&&f=='B'||e=='B'&&f=='A'||e=='A'&&f=='C'||e=='C'&&f=='A'||e=='B'&&f=='C'||e=='C'&&f=='B'){
                cout<<1;
            }
            else {
                cout<<"00";return 0;
            }
            if(e=='F'&&f=='D'||e=='D'&&f=='F'||e=='A'&&f=='B'||e=='B'&&f=='A'||e=='B'&&f=='C'||e=='C'&&f=='B')
                cout<<1;
            else cout<<0;
        }
    }
    return 0;
}
