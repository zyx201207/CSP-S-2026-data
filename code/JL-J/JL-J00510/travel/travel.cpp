#include <bits/stdc++.h>
using namespace std;
int main(){
    bool b=false,f=false;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string s1,s2;
    cin>>n>>s1>>m>>s2;
    if(n==m){
        cout<<1;
        f=true;
    }
    else cout<<0;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&f){
        cout<<1;
        b=true;
    }
    else cout<<0;
    if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'&&s1[2]<='F'&&s2[2]<='F'))&&b&&f)cout<<1;
    else cout<<0;
    if((s1[2]+1==s2[2]||s2[2]+1==s1[2])&&b&&f)cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
