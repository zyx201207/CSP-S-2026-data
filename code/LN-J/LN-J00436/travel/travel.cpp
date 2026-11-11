#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool an1,an2,an3,an4;
    char c1[3],c2[3],s1[4],s2[4];
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1]){
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')){
        cout<<"1100";
        return 0;
    }
    if(s1[2]-s2[2]!=1&&s2[2]-s1[2]!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
    
