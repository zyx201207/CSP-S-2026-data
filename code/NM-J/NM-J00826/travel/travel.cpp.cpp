#include<bits/stdc++.h>
using namespace std;
#define int long long;
signed main(){
    freopen(travel.in,"r",stdin);
    freopen(travel.out,"w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1><>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else cout<<0;
    if((s1[2]=='D'||s1[2]=='F')&&(s1[2]=='D'||s1[2]=='F'))
    {
        cout<<11;
        return 0;
    }else if((s1[2]=='A'||s1[2]=='C')&&(s1[2]=='A'||s1[2]=='C')){
        cout<<10;
        return 0;
    }else if((s1[2]=='A'||s1[2]=='B')&&(s1[2]=='A'||s1[2]=='B'))||((s1[2]=='B'||s1[2]=='C')&&(s1[2]=='B'||s1[2]=='C')){
        cout<<11;
        return 0;
    }else if((s1[2]=='D'||s1[2]=='C')&&(s1[2]=='D'||s1[2]=='C')){
        cout<<01;
        return 0;
    }else{
        cout<<00;
        return 0;
    }
       return 0;
}
