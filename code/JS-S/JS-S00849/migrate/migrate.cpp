#include<bits/stdc++.h>
using namespace std;
long long a[200004];
long long n,d,cnt;
void dfs(int x,int y,int now,int now2){
    if(now==y) return;
    for(int k=now2-1;k>=1;--k){
        if(a[now]-a[k]<=d) cnt++;
    }
    for(int k=now;k<=n;++k){
        if(a[k]-a[now]>d){
            dfs(x,y,min(k-1,y),now);
            return ;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>a[i];
        int f=1;
        for(int i=2;i<n;++i){
            if(a[i]-a[i+1]!=a[1]-a[2]) f=0;
        }
        if(f==1){
            long long s=d/(a[2]-a[1]);
            long long s2=s*2-1;
            if(n-s2>0)cout<<n-s2<<endl;
            else cout<<0;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                cnt=0;
                dfs(i,j,i,a[1]-2*d);
                if(cnt==1) ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
