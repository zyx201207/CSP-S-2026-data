#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],s[MAXN],l,mid,r,ans;
signed main()
{
//#ifndef ZYdeBuG
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
//#endif // ZYdeBuG
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stable_sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        l=1;r=i;int cnt=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
                cnt=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-cnt+1);
    }
    cout<<ans<<'\n';
    return 0;
}


