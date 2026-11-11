#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
int n;
ll m,a[maxn],d[maxn];
__int128 sum[maxn],b[maxn];
bool check(int x){
    for(int r=x; r<=n; r++){
        int l=r-x+1;
        if(b[r]-b[l]-(l-1)*(sum[r]-sum[l])<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2; i<=n; i++){
        d[i]=a[i]-a[i-1];
        sum[i]=sum[i-1]+d[i];
        b[i]=b[i-1]+(i-1)*d[i];
    }
    int l=1,r=n;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    printf("%d",l);
    return 0;
}
