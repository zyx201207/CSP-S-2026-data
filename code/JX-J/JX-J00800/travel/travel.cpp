#include <bits/stdc++.h>
using name pace std;
int main(){
    freopen("travel.in","r","std.in);
    freopen("travel.out","w","std.out");
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&s1!=s2){
        cout<<"1010";
    }else if(c1==c1&&s1==s2){
        cout<<"1111";
    }else if(c1!==c2&&s1!==s2){
        cout<<"0000";
    }else if(c1==c2&&s1==s2){
        cout<<"1111";
    }
    return 0;
}
