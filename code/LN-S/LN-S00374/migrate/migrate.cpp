#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,d;
int a[2000010];
int f[2000010];
int g[2000010];
int din[2000010];
int di[2000010];
int ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&T,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n&&a[j]<=a[i]+d;j++){
                din[j]++;
            }
        }
        int ans=0;
        for(int x=1;x<=n;x++){
            for(int i=1;i<=n;i++){
                di[i]=din[i];
            }
            memset(f,0x3f,sizeof(f));
            queue<int> q;
            q.push(x);
            g[x]=1;
            f[x]=0;
            while(!q.empty()){
                int p=q.front();
                q.pop();
                for(int i=p+1;i<=n&&a[i]<=a[p]+d;i++){
                    di[i]--;
                    if(f[p]+1<f[i]){
                        f[i]=f[p]+1;
                        g[i]=g[p];
                    }else if(f[p]+1==f[i]){
                        g[i]+=g[p];
                    }
                    if(di[i]==0){
                        q.push(i);
                    }
                }
            }
            for(int i=x;i<=n;i++){
                ans+=(g[i]==2);
            }
            for(int i=x+1;i<=n&&a[i]<=a[x]+d;i++){
                din[i]--;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
