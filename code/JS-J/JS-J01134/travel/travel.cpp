#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    string a2,b2,ans="";
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        ans="0000";
        cout<<ans;
        return 0;
    }
    if(a2[0]!=b2[0]||a2[1]!=b2[1]){
        ans="1000";
        cout<<ans;
        return 0;
    }
    if(a2[2]>='D'&&b2[2]>='D'){
        ans="1111";
        cout<<ans;
        return 0;
    }
    if(a2[2]<='C'&&b2[2]<='C'){
        if(abs(a2[2]-b2[2])==1){
            ans="1111";
        }
        else{
            ans="1110";
        }
        cout<<ans;
        return 0;
    }
    ans="1100";
    cout<<ans;
    return 0;
}
