#include <bits/stdc++.h>
using namespace std;

#define int long long

string c1,s1,c2,s2;

/*
                 (__) 
                 (oo) 
           /------\/ 
          / |    ||   
         *  /\---/\ 
            ~~   ~~   
..."Have you mooed today?"...
*/

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool isSameTrain=(c1==c2);
    cout<<(c1==c2);
    char lp1=s1.back(),lp2=s2.back();
    s1.pop_back(),s2.pop_back();
    bool isSameLine,isSameSide;
    if(isSameTrain){
        isSameLine=s1==s2;
        cout<<isSameLine;
    }else cout<<0,isSameLine=0;
    if(isSameLine){
        if((lp1<='C'&&lp2<='C')||(lp1>'C'&&lp2>'C'))isSameSide=1;
        cout<<isSameSide;
    }else cout<<0,isSameSide=0;
    if(isSameSide){
        cout<<(abs(lp1-lp2)==1);
    }else cout<<0;
}