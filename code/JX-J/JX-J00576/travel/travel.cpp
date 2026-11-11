#include<bits/stdc++.h>
using namespace std;
bool same_side(string a,string b){
    if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')){
            return true;
    }
    else if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')){
            return true;
    }
    return 0;
}
bool is_nearby(string a,string b){
    if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[2]=='A'||a[2]=='B'&&b[2]=='C'||a[2]=='C'&&b[2]=='B'||a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D') return true;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&same_side(s1,s2)) cout<<1;
    else cout<<0;
    if(c1==c2&&is_nearby(s1,s2)&&s1[1]==s2[1]) cout<<1;
    else cout<<0;
    return 0;
}
