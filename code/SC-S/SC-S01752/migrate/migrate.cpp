#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int x[N];;
int mi[N],q[N];
int f[N],g[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,_;scanf("%lld%lld",&c,&_);
    while(_--){
        int n,d;scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
        for(int i=1,j=1;i<=n;i++){
            while(x[i]-x[j]>d) j++;
            q[i]=j;
        }
        int x1=-x[1]+1;
        for(int i=1;i<=n;i++) x[i]+=x1;
        if(c>=11 && c<=12){
            int dd=x[2]-x[1];
            if(d/dd<2) printf("0\n");
            else printf("%lld\n",max(0ll,n-d/dd*2+1));
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) mi[j]=g[j]=0,f[j]=1;
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d) mi[j]=1;
                else if(mi[q[j]]>0) mi[j]=mi[q[j]]+1;
                else break;
            }
            for(int j=i+1;j<=n;j++){
                if(mi[j]==1) f[j]=0;
                if(mi[j]<=1) continue;
                int cnt=0;
                f[j]=0;
                int flag=0;
                for(int k=q[j];k<j;k++){
                    if(mi[j]==mi[k]+1) f[j]|=f[k],cnt++,flag|=g[k];
                    else break;
                }
                if(cnt>2 || cnt==0) f[j]=1;
                if(cnt==2 && flag==1) f[j]=1;
                if(f[j]==0 && (cnt==2 || flag==1)) g[j]=1,ans++;
                // printf("<%lld %lld>",i,j);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}