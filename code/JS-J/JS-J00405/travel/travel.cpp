#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
bool c1_b=false,s1_b=false,c2_b=false,s2_b=false;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        c1_b=true;
    }
    if(c1_b && s1[0]*100+s1[1]==s2[0]*100+s2[1]){
        s1_b=true;
    }
    if(s1_b && ((s1[2]>='D' && s2[2]>='D') || (s1[2]<='C' && s2[2]<='C'))){
        c2_b=true;
    }if(c2_b && (abs(s1[2]-s2[2])==1)){
        s2_b=true;
    }cout<<c1_b<<s1_b<<c2_b<<s2_b<<endl;
    return 0;
}