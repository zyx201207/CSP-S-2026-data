#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    if(s1!=s2){
        cout<<"0000";
        return 0;
    }
    if(c1[0]!=c2[0]||c1[1]!=c2[1]){
        cout<<"1000";
        return 0;
    }
    char _1=min(c1[2],c2[2]),_2=max(c1[2],c2[2]);
    if(_1=='A'&&_2=='C'){
        cout<<"1110";
        return 0;
    }
    if(_1=='D'&&_2=='F'){
        cout<<"1111";
        return 0;
    }
    if((_1=='A'&&_2=='B')||(_1=='B'&&_2=='C')){
        cout<<"1111";
        return 0;
    }
    if(_1>='A'&&_1<='C'&&_2>='D'&&_2<='F'){
        cout<<"1100";
        return 0;
    }
    return 0;
}
