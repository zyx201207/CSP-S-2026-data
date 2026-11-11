#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,a[200005],pw[35];
bool fA=true,fB=true,vis[25];
void dfs(int dep,long long sum,int cnt){
    if(dep>n){
        if(cnt==m) ans=max(sum,ans);
        return;
    }
    if(n-dep+1+cnt<m) return;
    if(cnt>m) return;
    dfs(dep+1,sum,cnt);
    if(sum==-1) sum=a[dep];
    else sum=(sum&a[dep]);
    dfs(dep+1,sum,cnt+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if((n&(n-1))!=0) fB=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if((a[i]&(a[i]+1))!=0) fA=false;
        if(a[i]!=i-1) fB=false;
    }
    pw[0]=1;
    for(int i=1;i<=30;i++) pw[i]=pw[i-1]*2;
    if(n<=20){
        dfs(1,-1,0);
        cout<<ans;
        return 0;
    }
    if(m==1){
        long long maxn=-1;
        for(int i=1;i<=n;i++) maxn=max(a[i],maxn);
        cout<<maxn;
        return 0;
    }
    if(m==n){
        long long tmp=a[1];
        for(int i=2;i<=n;i++) tmp=tmp&a[i];
        cout<<tmp;
        return 0;
    }
    if(m==2&&n<=2000){
        long long ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(fA){
        sort(a+1,a+n+1);
        cout<<a[m];
        return 0;
    }
    if(fB){
        cout<<n-m;
        return 0;
    }
    return 0;
}