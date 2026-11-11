#include<bits/stdc++.h>
using namespace std;
int agb[1005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s1,c1;
    string s2,c2;
    cin>>s1>>s2>>c1>>c2;
    //1
    if(c1!=s1){
        cout<<0<<0<<0<<0;
        return 0;
    }
    else cout<<1;
    //2
    if(!(s2[0]==c2[0]&&s2[1]==c2[1])){
        cout<<0<<0<<0;
        return 0;
    }
    else cout<<1;
    //3

    int a=0,b=0;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
        a=1;
    else a=2;
    if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')
        b=1;
    else b=2;
    if(a!=b){
        cout<<0<<0;
        return 0;
    }
    else cout<<1;
    //4

    if(c2[2]=='A'&&s2[2]=='C'||c2[2]=='C'&&s2[2]=='A')
        cout<<0;
    else cout<<1;
    return 0;
}
