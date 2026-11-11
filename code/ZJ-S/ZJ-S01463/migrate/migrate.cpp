#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
int dist[2000005],f[2000005];
int lst[2000005],sum[2000005];
int lft[2000005],rght[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T,n,d;
    scanf("%lld%lld",&c,&T);
    while (T--){
        scanf("%lld%lld",&n,&d);
        for (int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        if (c>=1&&c<=10){
            int ans=0;
            for (int i=1;i<=n;i++){
                int l=i;
                dist[i]=0;f[i]=1;
                lst[0]=i;
                sum[i-1]=0;sum[i]=1;
                for (int j=i+1;j<=n;j++){
                    while (x[j]-x[l]>d)l++;
                    if (l==j)break;
                    dist[j]=dist[l]+1;
                    lst[dist[j]]=j;
                    f[j]=sum[lst[dist[l]]]-sum[l-1];
                    sum[j]=sum[j-1]+f[j];
                    if (f[j]==2)ans++;
                }
            }
            printf("%lld\n",ans);
        }
        else if (c==11||c==12){
            f[1]=1;
            sum[1]=1;
            sum[0]=0;
            dist[1]=0;
            lst[0]=1;
            int ans=0,l=1;
            for (int j=2;j<=n;j++){
                while (x[j]-x[l]>d)l++;
                if (l==j)break;
                dist[j]=dist[l]+1;
                lst[dist[j]]=j;
                f[j]=sum[lst[dist[l]]]-sum[l-1];
                sum[j]=sum[j-1]+f[j];
                if (f[j]==2)ans+=n-j+1;
            }
            printf("%lld\n",ans);
        }
        else if (c==13||c==14){
            int l=1;
            lft[1]=-1;
            for (int i=2;i<=n;i++){
                while (x[i]-x[l]>d)l++;
                lft[i]=l;
            }
            int r=n;
            rght[n]=-1;
            for (int i=n-1;i>=1;i--){
                while (x[r]-x[i]>d)r--;
                rght[i]=r;
            }
            l=1;r=0;
            int ans=0;
            for (int i=2;i<=n;i++){
                while (rght[l]<lft[i]+1)l++;
                while (rght[r+1]<=lft[i]+1)r++;
                ans+=(r-l+1);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}