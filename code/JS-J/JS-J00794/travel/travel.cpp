#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(s1[1]==s2[1]&&s1[0]==s2[0])cout<<1;
    else {
        cout<<0<<0<<0;
        return 0;
    }
    a=s1[2];
    b=s2[2];
    if(a=='A'||a=='B'||a=='C'){
        if(b=='A'||b=='B'||b=='C')cout<<1;
        else cout<<0;
    }else{
        if(b=='F'||b=='D') cout<<1;
        else  cout<<0;
    }
    if(a-'0'-1==b-'0'||b-'0'-1==a-'0'){
            if(a!='C'&&b!='D'&&a!='D'&&b!='C') cout<<1;
            else cout<<0;
    }else cout<<0;
    return 0;
}
