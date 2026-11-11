#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,s1,s2;
    cin>>a1>>s1>>a2>>s2;
    if(a1!=a2){
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    if((s1[2]=='D'&&s2[2]!='F')||(s2[2]=='D'&&s1[2]!='F')||(s1[2]=='F'&&s2[2]!='D')||(s2[2]=='F'&&s1[2]!='D')){
        cout<<"1100";
        return 0;
    }
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
        cout<<"1111";
        return 0;
    }
    cout<<"1110";
    return 0;
}

