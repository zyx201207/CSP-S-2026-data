#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int m,ans=0,t=0;
    string s;
    cin>>m;
    for(int i=1;i<=m;i++){
        long long x;
        char bit;
        cin>>x>>bit;
        for(long long j=1;j<=x;j++){
            s=s+bit;
        }
    }
    int l=s.size();
    string s1;
    for(int i=l-1;i>=0;i--){
        s1=s1+s[i];
    }
    for(int i=0;i<=l-1;i++){
        if(s1[i]!=s[i]){
            s1[i]=s[i];
            s[l-1-i]=s1[i];
            ans++;
        }
    }
    for(int i=l-1;i>=0;i--){
        if(s1[i]!=s[i]){
            s1[i]=s[i];
            s[l-1-i]=s1[i];
            t++;
        }
    }
    if(t>0){
        cout<<min(ans,t);
    }else cout<<ans;
    return 0;
}

