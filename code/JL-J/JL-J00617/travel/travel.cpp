#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char k1,k2;
    bool x=0,p=0,c=0,l=0;
    cin>>c1>>s1>>k1>>c2>>s2>>k2;
    if(c1==c2){
        x=1;
    }
    if(s1==s2){
        p=1;
    }
    if(k1=='A'&&k2=='B'||k1=='B'&&k2=='A'||k1=='C'&&k2=='A'||k1=='A'&&k2=='C'||k1=='C'&&k2=='B'||k1=='B'&&k2=='C'||k1=='D'&&k2=='F'||k1=='F'&&k2=='D'){
        c=1;
    }
    if(k1=='A'&&k2=='B'||k1=='B'&&k2=='A'||k1=='B'&&k2=='C'||k1=='C'&&k2=='B'||k1=='D'&&k2=='F'||k1=='F'&&k2=='D'){
        l=1;
    }
    cout<<x<<p<<c<<l;
    return 0;
}
