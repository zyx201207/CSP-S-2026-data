#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if('s1'-'s2'==1||'s2'-'s1'==1){
        cout<<"111";
    }
    return 0;
}
