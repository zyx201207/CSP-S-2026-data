#include<bits/stdc++.h>
using namespace std;
string a2,b2,a1,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
cin>>a1>>a2>>b1>>b2;
if(a1[0]==a2[0] && a1[1]==b1[1]){
    if(b2[0]==a2[0] && a2[1]==b2[1]){
        if(a2[2]<='C' && b2[2]<='C'){
            if(max(int(a2[2]),int(b2[2]))-min(int(a2[2]),int(b2[2]))==1) cout<<"1111";
            else cout<<"1110";
        }
        else if(b2[2]>='D' && a2[2]>='D'){
            if(max(int(a2[2]),int(b2[2]))-min(int(a2[2]),int(b2[2]))==1) cout<<"1111";
            else cout<<"1110";
        }
        else cout<<"1100";
    }
    else cout<<"1000";
}
else cout<<"0000";
return 0;
}

