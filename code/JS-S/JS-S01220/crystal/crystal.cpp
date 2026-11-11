#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,mx=1e12;
int n,m,a[N],qrys[N],ans[N],pre[N];
bool tst[N];

bool check(int key){
    int mn=1e18;
    for(int i=key;i<=n;i++){
        mn=min(mn,a[i]*key-(pre[i]-pre[i-key]));
    }
    return mn<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=n,mid,ans=1;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}