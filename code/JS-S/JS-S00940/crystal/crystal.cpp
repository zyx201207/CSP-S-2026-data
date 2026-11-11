#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
int n;
ll m;//m can be 0
ll a[N],sum[N];
bool chk(int x){
    for(int i=1;i<=n-x+1;i++){
        ll cost=a[i+x-1]*(1LL*x)-(sum[i+x-1]-sum[i-1]);
        if(cost<=m){
            return true;
        }
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int L=1,R=n+1,res=1;
    while(L<=R){
        int mid=(L+R)/2;
        if(chk(mid)){
            L=mid+1;
            res=mid;
        }
        else{
            R=mid-1;
        }
    }
    printf("%d\n",res);
    return 0;
}
