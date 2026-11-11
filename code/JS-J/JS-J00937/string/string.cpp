#include<bits/stdc++.h>
using namespace std;
int b[200004];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    int s1=0,num=0;
    for(int i=1;i<=n;++i){
        int a;cin>>a;
        char c;cin>>c;
        s1+=a;
        for(int j=1;j<=a;++j) b[++num]=c-'a'+1;
    }
    int ans=0;
    for(int i=1;i<=s1/2;++i){
        if(b[i]!=b[s1+1-i]) ans++;
    }
    cout<<ans;
    return 0;
}
