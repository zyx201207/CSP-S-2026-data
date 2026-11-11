#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"000";
        return 0;
    }cout<<1;
    int a,b;
    a=int(s1[2]),b=int(s2[2]);
    if(a>67&&b<=67||a<68&&b>=68){
        cout<<"00";
        return 0;
    }cout<<1;
    if(a>=68){
        cout<<1;
        return 0;
    }if(a<=67){
        if(a<b&&a+2==b){
            cout<<0;
            return 0;
        }if(a>b&&a-2==b){
            cout<<0;
            return 0;
        }
    }cout<<1;
    return 0;
}
