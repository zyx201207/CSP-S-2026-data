#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    if(a==b){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if((s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if((s1[2]<=67&&s2[2]<=67)||(s1[2]>67&&s2[2]>67)){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs(s1[2]-s2[2])==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
