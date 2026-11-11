#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
int n;
ll m,a[N],s[N];
bool check(int len){
    for(int i=len;i<=n;i++){
        ll op=1ll*len*a[i]-(s[i]-s[i-len]);
        if(op<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    printf("%d",l-1);
    return 0;
}
