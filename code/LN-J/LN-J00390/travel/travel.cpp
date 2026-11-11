#include<bits/stdc++.h>
using namespace std;
int a1,a2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a1>>s1>>a2>>s2;
    if(a1==a2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }

    int b1=(s1[0]-'0')*10+(s1[1]-'0'),b2=(s2[0]-'0')*10+(s2[1]-'0');
    if(b1==b2){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }

    if((s1[2]<='C' && s2[2]<='C')|| (s1[2]>='D' && s2[2]>='D')){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }

    if(max(s1[2],s2[2])-min(s1[2],s2[2])==1 ||max(s1[2],s2[2])=='F' && min(s1[2],s2[2])=='D'){
        cout<<1;
    }
    else{
        cout<<0;
    }

    return 0;
}
