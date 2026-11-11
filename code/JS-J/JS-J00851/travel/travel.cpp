#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2,p1,p2;
bool check(char a,char b){
    return (s1[2]==a&&s2[2]==b)||(s1[2]==b&&s2[2]==a);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    p1=s1[0]+s1[1];
    p2=s2[0]+s2[1];
    if(c1==c2)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(p1==p2)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(
        ('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||
        ('D'<=s1[2]&&s1[2]<='E'&&'D'<=s2[2]&&s2[2]<='E')){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }

    if(check('A','B')||check('B','C')||check('D','F'))cout<<1;
    else cout<<"0";
    return 0;
}
/*
Think:
shi ren jiu neng xie
*/
