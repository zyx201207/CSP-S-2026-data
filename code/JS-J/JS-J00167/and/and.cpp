#include<bits/stdc++.h>
using namespace std;
int a[200001],f[200001][32],p[32];
int u[200001],h[200001],an[32];
int change(int n){
    int t=a[n];
    int tot=0;
    while(t>0){
        f[n][tot]=t%2;
        tot++;
        t/=2;
    }
    return tot;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    p[0]=1;
    for(int i=1;i<=30;i++){
        p[i]=p[i-1]*2;
    }
    int n,m,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(change(i),maxn);
    }
    for(int i=maxn;i>=0;i--){
        int s=0;
        for(int j=1;j<=n;j++){
            if(u[j]==0&&f[j][i]==1)s++;
        }
        if(s>=m){
            an[i]=1;
            for(int j=1;j<=n;j++){
                if(f[j][i]==0)u[j]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=maxn;i++){
        ans+=an[i]*p[i];
    }
    cout<<ans;
    return 0;
}
