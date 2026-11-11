#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a=1,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else{
        if(s1[0]==s2[0] and s1[1]==s2[1]){
            b = 1;
            if((s1[2]<='C' and s2[2]<='C')||(s1[2]>='D' and s2[2]>='D')){
            c = 1;
            if((s1[2]=='C' and s1[2]=='D') ||(s1[2]=='D' and s2[2]=='C')){
            d = 0;
        }else if(abs(s1[2]-s2[2])==1){
            d = 1; }
    else if((s1[2]=='D' and s2[2]=='F') ||(s1[2]=='F' and s2[2]=='D')){
            d = 1;
    }
        }
        }
    }
cout<<a<<b<<c<<d;
return 0;
}
