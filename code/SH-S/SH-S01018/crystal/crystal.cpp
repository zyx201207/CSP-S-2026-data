#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+9;
int n,ans;
ll m,a[N];
int find(int x,ll d){
    int l=1,r=x;
    while(l<r){
        int mid=(l+r)>>1;
        if(d*(1ll*(x-mid+1))-(a[x]-a[mid-1])<=m)r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ll tmp=a[i];
        a[i]+=a[i-1];
        ans=max(ans,i-find(i,tmp)+1);
    }
    printf("%d",ans);
    return 0;
}