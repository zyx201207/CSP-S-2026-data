#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(s1[0] + s1[1]==s2[0] + s2[1]){
        cout<<1;
        char a = s1[2];
        char b = s2[2];
        if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
            cout<<1;
            if(abs(a-b)==1) cout<<1;
            else cout<<0;
        }else if((a=='D'||a=='E')&&(b=='D'||b=='E')){
            cout<<1;
            if(abs(a-b)==1) cout<<1;
            else cout<<0;
        }else{
            cout<<0<<0;
            return 0;
        }
    }else{
        cout<<0<<0<<0;
        return 0;
    }
    return 0;
}
