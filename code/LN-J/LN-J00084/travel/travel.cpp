#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char a,b;
bool f=0;
bool check(){
    if(a=='A'&&b=='B'||a=='B'&&b=='A'){
        f=1;
        return 1;
    }
    if(a=='A'&&b=='C'||a=='C'&&b=='A')return 1;
    if(a=='B'&&b=='C'||a=='C'&&b=='B'){
        f=1;
        return 1;
    }
    if(a=='D'&&b=='F'||a=='F'&&b=='D'){
        f=1;
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>a>>c2>>s2>>b;
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            if(check()){
                cout<<1;
                cout<<f;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
