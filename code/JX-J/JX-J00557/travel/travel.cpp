#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>e>>c>>d>>f;
    if(e>f) swap(e,f);
    cout<<(a==c)<<(a==c&&b==d)<<(a==c&&b==d&&(e=='A'&&f=='B'||e=='B'&&f=='C'||e=='A'&&f=='C'||e=='D'&&f=='F'))<<(a==c&&b==d&&(e=='A'&&f=='B'||e=='B'&&f=='C'||e=='D'&&f=='F'));
    return 0;
}
