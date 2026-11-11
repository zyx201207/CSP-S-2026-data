#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    int cnt=s1[0]+s1[1];
    int cnt1=s2[0]+s2[1];
    if(cnt==cnt1){
        cout<<1;
    }
    else {
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    char a=s1[2];
    char b=s2[2];
    if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
            cout<<1;
    }
    else if(a>='D'&&a<='F'&&b>='D'&&b<='F'){
            cout<<1;
    }
    else {
        cout<<0;
        cout<<0;
        return 0;
    }
    if(a-b==1||b-a==1){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
