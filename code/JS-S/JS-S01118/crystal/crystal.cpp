#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N=500010;

int n;
LL m;
LL a[N],s[N],p[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);

    sort(a+1, a+1+n);
    for(int i=1;i<=n;i++)s[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)p[i]=s[i]*i;

    for(int i=1;i<=n;i++)s[i]+=s[i-1];
    for(int i=1;i<=n;i++)p[i]+=p[i-1];

    int ans=0;
    for(int i=1;i<=n;){
        int vis=1,pos=i+1;
        while(a[pos]==a[i])pos++,vis++;

        int l=0,r=i;
        while(l<r){
            int mid=(l+r+1)>>1;
            long long calculate=p[i]-p[i-mid]-(i-mid)*(s[i]-s[i-mid]);
            if(calculate<=m)l=mid;
            else r=mid-1;
        }

        ans=max(ans,l+vis);
        i+=vis;
    }

    printf("%d\n",ans);

    return 0;
}
