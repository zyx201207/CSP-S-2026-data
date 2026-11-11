#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,a[N],ans;
long long m,s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    s[0]=0;
    for (int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;i++){
        int l=1,r=i;
        while (l<r-1){
            int mid=(l+r)/2;
            if (a[i]*(i-mid+1)-(s[r]-s[mid-1])<=m)
                r=mid;
            else
                l=mid;
        }
        if (a[i]*(i-l+1)-(s[i]-s[l-1])<=m)
            ans=max(ans,i-l+1);
        else
            ans=max(ans,i-r+1);
    }
    printf("%d",ans);
    return 0;
}
