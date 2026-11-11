#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    bool f1;
    char a=s2[2],b=s4[2];
    string c1=s2;
    string c2=s4;
    c1.pop_back(),c2.pop_back();
    int d1,d2;
    if(a=='A' || a=='B'||a=='C'){
        d1=0;
    }
    else d1=1;
    if(b=='A' || b=='B'||b=='C'){
        d2=0;
    }
    else d2=1;
    if(s1==s3) {
        cout<<1;
        f1=true;
    }
    else{
        cout<<0;
        f1=false;
    }
    if(f1==false||c1!=c2){
        cout<<"000";
        return 0;
    }else{
        cout<<1;
    }
    if(d1==d2){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(a-b)==1){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
