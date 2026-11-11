#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+10;
int n,res;
ll m;
ll a[N],sa[N];

int main(){ // 100
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;++i) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) sa[i]=sa[i-1]+a[i];
    for (int i=1;i<=n;++i){
        int left=1,right=i-1;
        while (left<=right){
            int mid=(left+right)>>1;
            if (sa[i-1]-sa[i-mid-1]+m>=a[i]*mid) left=mid+1;
            else right=mid-1;
        }
        res=max(res,left);
    }
    printf("%d",res);
    return 0;
}
