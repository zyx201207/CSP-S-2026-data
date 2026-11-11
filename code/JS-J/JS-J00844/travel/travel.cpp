#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]!=c2[1]||c1[0]!=c2[0]){
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    if((s1[2]-'A'>2&&s2[2]-'A'<3)||(s2[2]-'A'>2&&s1[2]-'A'<3)){
        cout<<"1100";
        return 0;
    }
    if(abs(s1[2]-s2[2])>1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
