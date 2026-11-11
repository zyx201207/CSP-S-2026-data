#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,cnt,ans,l,r,a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    l=1;a[0]=a[1];
    for(r=1;r<=n;r++){
        cnt+=(a[r]-a[r-1])*(r-l);
        while(cnt>m){
            cnt-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
