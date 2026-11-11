#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],key,s;
long long ans;
void dfs(int ip,int cnt,long long answer){
    if(cnt==m){ans=max(ans,answer);return ;}
    for(int i=ip+1;i<=n;i++){
        dfs(i,cnt+1,answer&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        s=a[i]+1;
        while(s>1) {if(s%2==0) s/=2; else { key=1; } }
    }
    if(!key){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++) ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    //if(n<=2000){
    for(int i=1;i<=n-m;i++){
        dfs(i,1,a[i]);
    }
    cout<<ans;
    //return 0;
    //}


    return 0;
}
