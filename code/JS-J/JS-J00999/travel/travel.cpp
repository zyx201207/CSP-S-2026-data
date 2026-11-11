#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=true;
void solve(){
    if(c1==c2){
        cout<<1;
    }else{
        flag=false;
        cout<<0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag){
        cout<<1;
    }else{
        flag=false;
        cout<<0;
    }
    if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&flag){
        cout<<1;
    }else{
        flag=false;
        cout<<0;
    }
     if(abs(s1[2]-s2[2])==0&&flag){
        cout<<1;
    }else{
        cout<<0;
    }
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    solve();
    return 0;
}
