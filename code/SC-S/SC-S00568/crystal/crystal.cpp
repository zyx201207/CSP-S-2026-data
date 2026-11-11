#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;
long long arr[maxn],pre[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr+1,arr+1+n);
    int l=0,mx=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+arr[i];
        // fprintf(stderr,"%lld %lld\n",(i-l)*arr[i],pre[i]-pre[l]);
        while(l<i&&(((i-l)*arr[i]-(pre[i]-pre[l]))>m)) l++;
        mx=max(mx,i-l);
        // fprintf(stderr,"%d %d\n",i,l);
    }
    printf("%d\n",mx);
    return 0;
}