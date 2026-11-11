#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char a1,a2,b1,b2,ca,cb;
    for(int i=0;i<s1.size();i++){
        a1=s1[i];
        a2=s1[i+1];
        c1=s1[i+2];
    }
    for(int i=0;i<s2.size();i++){
        a2=s2[i];
        a2=s2[i+1];
        ca=s2[i+2];
    }
    if(c1==c2 && s1!=s2){
        cout<<1;
    }
    else cout<<0;
    if(a1==a2 && b1==b2 && s1!=s2){
        cout<<1;
    }
    else cout<<0;
    if(a1==a2 && b1==b2 && s1!=s2){
        cout<<1;
    }
    else cout<<0;
    if(a1==a2 && b1+'1'==b2 && ca+'1'==cb && s1!=s2){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
