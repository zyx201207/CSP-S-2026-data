#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m,a[500005];

bool judge(int x){
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(i>=x){
            sum-=a[i-x];
            if(a[i]*x-sum<=m)
                return true;
        }
    }
    return false;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(judge(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",r);
    return 0;
}
