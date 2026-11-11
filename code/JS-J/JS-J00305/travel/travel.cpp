#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p1,p2;
char z1,z2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<=1;i++)p1+=s1[i];
    for(int i=0;i<=1;i++)p2+=s2[i];
    if(p1!=p2){
        cout<<"1000";
        return 0;
    }
    z1=min(s1[2],s2[2]);
    z2=max(s1[2],s2[2]);
    if(z1<='C'&&z2<='C'||z1>='D'&&z2>='D'){
        if((z1=='A'&&z2=='B')||(z1=='B'&&z2=='C')||(z1=='D'&&z2=='F'))cout<<"1111";
        else cout<<"1110";
    }
    else cout<<"1100";
    return 0;
}
