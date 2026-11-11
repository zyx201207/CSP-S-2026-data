#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int k1=0,k2=0,st1=0,st2=0;
    for(int i=0;i<c1.size();i++){
        k1*=10;
        k1+=c1[i]-'0';
    }
    for(int i=0;i<c2.size();i++){
        k2*=10;
        k2+=c2[i]-'0';
    }
    st1+=s1[0]-'0';
    st1*=10;
    st1+=s1[1]-'0';
    st1*=10;
    if(s1[2]=='D'){
        st1+=s1[2]-'A'+1;
    }else{
        st1+=s1[2]-'A';
    }
    st2+=s2[0]-'0';
    st2*=10;
    st2+=s2[1]-'0';
    st2*=10;
    if(s2[2]=='D'){
        st2+=s2[2]-'A'+1;
    }else{
        st2+=s2[2]-'A';
    }
    if(k1==k2){
        cout<<1;
    }else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(st1/10==st2/10){
        cout<<1;
    }else{
        cout<<0<<0<<0;
        return 0;
    }
    if((st1%10<=2&&st2%10<=2)||(st1%10>2&&st2%10>2)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(abs(st1-st2)==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
