#include<bits/stdc++.h>

using namespace std;
int num[1<<20],a[200001],vis[1<<20];
int pre[200001],suf[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,mx;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    if(n<=20){
        int ans=0;
        for(int s=1;s<(1<<n);s++){
            int res=(1<<30)-1;
            if(__builtin_popcount(s)!=m) continue;
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1))) res&=a[i];
            }
            ans=max(ans,res);
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        int ans=(1<<30)-1;
        for(int i=1;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            int res=a[i]&a[j];
            ans=max(ans,res);
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            if(i==1) pre[i]=a[i];
            else pre[i]=a[i]&pre[i-1];
        }
        for(int i=n;i>=1;i--){
            if(i==n) suf[i]=a[i];
            else suf[i]=suf[i+1]&a[i];
        }
        int ans=max(pre[n-1],suf[2]);
        for(int i=2;i<=n-1;i++) ans=max(ans,pre[i-1]&suf[i+1]);
        cout<<ans;
        return 0;
    }

    return 0;
}
