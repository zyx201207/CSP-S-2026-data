#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+9;
int c,t,n,suc[N],pre[N];
ll d,a[N],l[N],r[N];
ll cal_l(int x){
    if(pre[x]==x)return 1;
    int y=pre[x+1];
    if(y==pre[x])return 1;
    return l[x]+y-pre[x]-1;
}
ll cal_r(int x){
    if(suc[x]==x)return 1;
    int y=suc[x-1];
    if(y==suc[x])return 1;
    return r[x]+suc[x]-y-1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        ll ans=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",a+i);
            l[i]=r[i]=1ll,pre[i]=suc[i]=0;
        }
        for(int i=1;i<=n;i++){
            int j=lower_bound(a+1,a+1+n,a[i]-d)-a;
            pre[i]=j;
            if(j==i)continue;
            if(pre[j]==pre[j+1])l[i]=1;
            else l[i]+=l[j]+pre[j+1]-pre[j]-1;
        }
        for(int i=n;i;i--){
            int j=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
            suc[i]=j;
            if(j==i)continue;
            if(suc[j]==suc[j-1])r[i]=1;
            else r[i]+=r[j]+suc[j]-suc[j-1]-1;
        }
        for(int i=1;i<=n;i++){
            int j=suc[i],k=j-1;
            if(i>=k)continue;
            int L=suc[k-1]+1,R=suc[k];
            if(suc[j]!=R)ans+=cal_l(i)*(R-L+1);
            else ans+=cal_l(i)*(R-L+cal_r(R));
        }
        printf("%lld\n",ans);
    }
    return 0;
}