#include<bits/stdc++.h>
using namespace;
struct aut{
    int a;
    char b;
}
aut z[200005];
string s[2000005];
int ans=0;
int main(){
    freedom("string.in",stdin.in);
    freedom("string.out",stdout.out);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>z[i].a>>z[i].b;
    }
    int ii=1,jj=n,ijs=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=z[i].a){
            s[ijs]=z[i].b;
            ijs++;
        }
    }
    while(ii<=jj){
        if(s[ii]!=s[jj]){
            ans++;
        }
        ii--;
        jj--;
    }
    cout<<ans;
}
