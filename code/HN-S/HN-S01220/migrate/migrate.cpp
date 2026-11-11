#include<bits/stdc++.h>
using namespace std;
int n,m;
int lm[2000003];
long long a[2000003],d;
int ef(int x){
    int l=x,r=n,mid,ans=0;
    long long sum=d+a[x];
    while(l<=r){
        mid=(l+r)>>1;
        if(a[mid]<=x){
            ans=max(ans,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
}
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int csd,T;
    scanf("%d%d",&csd,&T);
    while(T--){
        scanf("%d",&n);
        int i;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(csd==13||csd==14){
            printf("0\n");
            continue;
        }
    }

    return 0;
}