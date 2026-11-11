#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool tong_che,tong_pai,tong_ce,xiang_ling;
    tong_che = (c1==c2);
    tong_pai = tong_che && (s1[0]==s2[0] && s1[1]==s2[1]);
    tong_ce = tong_pai && ((s1[2]<='C')==(s2[2]<='C'));
    xiang_ling = tong_ce && (abs(s1[2]-s2[2])==1);
    cout<<tong_che<<tong_pai<<tong_ce<<xiang_ling;
    return 0;
}
