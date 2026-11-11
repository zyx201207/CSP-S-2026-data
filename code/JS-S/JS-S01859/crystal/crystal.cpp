#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128_t
const int N=5e5+5;
int n;
ll m,a[N];
lll pre[N];
inline int count(int b,int e,lll v){
    int l=b,r=e,mid=b;
    b--;
    while(l<r){
        mid=(l+r)>>1;
        if(pre[mid]-pre[b]-v*(mid-b)<=m)l=mid+1;
        else r=mid-1;
    }return(pre[l]-pre[b]-v*(l-b)>m?l-1:l);
}int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+n+1,greater<ll>());
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[1]-a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(n-i+1<=ans)break;
        ans=max(ans,count(i,n,a[1]-a[i])-i+1);
    }printf("%d",ans);
    return 0;
}