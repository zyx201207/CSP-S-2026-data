#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

const int N=5e5+5;

ll a[N];
ll s[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n; ll m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)/2;
            ll v=a[i]*(i-mid+1)-s[i]+s[mid-1];
            if(v<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d\n",ans);
    return 0;
}
