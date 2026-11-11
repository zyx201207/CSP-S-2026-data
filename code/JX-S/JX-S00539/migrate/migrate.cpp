#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000050
#define pii pair<int,int>
#define fi first
#define se second
int C,t,n;
ll d,a[N],ans,mi[N],tot[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&t);
    while(t){
        t--;ans=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                mi[j]=1e9;tot[i]=0;
            }
            mi[i]=0;tot[i]=1;
            for(int j=i;j<=n;j++){
                if(tot[j]==2) ans++;
                int l=j+1;
                while(a[l]-a[j]<=d&&l<=n){
                    if(mi[l]>mi[j]+1) mi[l]=mi[j]+1,tot[l]=0;
                    if(mi[l]==mi[j]+1) tot[l]+=tot[j];
                    l++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
