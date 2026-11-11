#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
void fals(int x){
    for(int i=1;i<=x;i++) cout<<0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        fals(4);
        return 0;
    }if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else{
        fals(3);
        return 0;
    }if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')) cout<<1;
    else{
        fals(2);
        return 0;
    }cout<<(s1[2]+1==s2[2]||s1[2]-1==s2[2]);
    return 0;
}