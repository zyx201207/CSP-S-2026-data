#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1.substr(0,2)!=s2.substr(0,2)){
        cout<<"000";return 0;
    }
    cout<<1;
    char a=s1[2],b=s2[2];
    if((a>='A'&&a<='C'&&b>='D'&&b<='F')||(a>='D'&&a<='F'&&b>='A'&&b<='C')){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
