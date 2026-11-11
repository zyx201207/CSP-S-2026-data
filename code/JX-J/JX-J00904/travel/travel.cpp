#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int a, int b){
    if(a<=3 and b<=3) return true;
    if(a>=4 and b>=4) return true;
    return false;
}

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int a1,b1,a2,b2;
    if(s1[0]=='0'){
        a1=s1[1]-'0';
    }
    else{
        a1=10ll+s1[1]-'0';
    }
    if(s2[0]=='0'){
        a2=s2[1]-'0';
    }
    else{
        a2=10ll+s2[1]-'0';
    }
    b1=s1[2]-'A'+1ll;
    b2=s2[2]-'A'+1ll;
    if(c1==c2) cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(a1==a2)cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(check(b1,b2)){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(b1+1ll==b2 or b1-1ll==b2){
        cout<<"1";
    }
    else cout<<"0";
    return 0;
}
