#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+500;
int c,t,n,d,l[maxn],r[maxn],a[maxn],ans,nex[maxn],pre[maxn];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d),a[0]=-4e18,a[n+1]=4e18,ans=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]),l[i]=r[i]=0;
        if(11<=c&&c<=12){
            int k=d/(a[2]-a[1]);
            if(k<=1||k>=n)printf("0\n");
            else printf("%lld\n",n-k*2+1);
            continue;
        }
        for(int i=1,j=1;i<=n;i++){
            while(a[j+1]-a[i]<=d)j++;
            nex[i]=j;
            if(i!=j)l[j]=max(l[j],l[i]+1);
        }
        for(int i=n,j=n;i;i--){
            while(a[i]-a[j-1]<=d)j--;
            pre[i]=j;
            if(i!=j)r[j]=max(r[j],r[i]+1);
        }
        // for(int i=1;i<=n;i++)
        //     l[i]=pre[i]==i?0:l[pre[i]]+1;
        // for(int i=n;i;i--)
        //     r[i]=nex[i]==i?0:r[nex[i]]+1;
        // printf("l:");
        // for(int i=1;i<=n;i++)
        //     printf("%lld ",l[i]);
        // printf("\n");
        // printf("r:");
        // for(int i=1;i<=n;i++)
        //     printf("%lld ",r[i]);
        // printf("\n");
        for(int i=2,j=3,L,R,k1,k2;j<n;i++,j++){
            L=R=0;
            if(a[j]-a[i]<=d){
                k1=lower_bound(a+1,a+1+n,a[j]-d)-a;
                if(k1<i&&a[k1]<a[j+1]-d){
                    k2=lower_bound(a+1,a+1+n,a[j+1]-d)-a-1,k2=min(k2,i-1);
                    if(k1<=k2){
                        if(a[i]-a[k1-1]<=d)L=1;
                        else L=l[k1]+k2-k1+1;
                    }
                }
                k2=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
                if(k2>j&&k2<=n&&a[k2]-a[i-1]>d){
                    k1=upper_bound(a+1,a+1+n,a[i-1]+d)-a,k1=max(k1,j+1);
                    if(k1<=k2){
                        if(a[k2+1]-a[j]<=d)R=1;
                        else R=r[k2]+k2-k1+1;
                    }
                }
            }ans+=L*R;
            // printf("%lld %lld %lld\n",i,L,R);
        }printf("%lld\n",ans);
    }
    return 0;
}