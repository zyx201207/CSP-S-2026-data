#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int sum[N],num[N];
int ans=1;
bool check(int l,int r){
    int x=sum[r]-sum[l-1];
    int res=(r-l+1)*a[r]-x;
    return res<=m;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l,r,mid;
    for(int i=2;i<=n;i++){
        l=0,r=i-1;
        while(l+1<r){
            mid=l+r>>1;
            mid=max(mid,1ll);
            if(check(mid,i)) r=mid;
            else l=mid;
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<endl;
    return 0;
}
