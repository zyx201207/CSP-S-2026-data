#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],cnt,l,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    l=1;
    ans=1;
    for (int i=2;i<=n;++i){
        cnt+=(i-l)*(a[i]-a[i-1]);
        if (cnt>m){
            while(cnt>m){
                cnt-=(a[i]-a[l]);
                l++;
            }
        }
        ans=max((i-l+1),ans);
    }
    cout<<ans;
    return 0;
}
