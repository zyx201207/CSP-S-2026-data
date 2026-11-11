#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(s1[1]!=s2[1]||s1[0]!=s2[0]){
        cout<<1000;
        return 0;
    }
    if((min(s1[2],s2[2])=='D'&&max(s1[2],s2[2])=='F')
    ||(s1[2]!='F'&&s2[2]!='F'&&s1[2]!='D'&&s2[2]!='D')){
        if(abs(s1[2]-s2[2])==1) cout<<1111;
        else cout<<1110;
    }else{
        cout<<1100;
    }
    return 0;
}