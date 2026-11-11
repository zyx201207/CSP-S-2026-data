#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=500010;
i64 n,m;
i64 a[N];
i64 s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        int pos=i;
        while(l<=r){
            mid=(l+r)>>1;
            if(1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
                pos=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,i-pos+1);
    }
    cout<<ans<<"\n";
    return 0;
}
/*

*/