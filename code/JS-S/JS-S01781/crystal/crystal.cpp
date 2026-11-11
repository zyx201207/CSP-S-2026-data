#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans = 0;
int a[500005],s[500005];
bool check(int x,int y){
    int k = (y-x+1);
    int r = (s[y]-s[x-1]);
    if(k*a[y] -r <= m) return 1;
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) s[i] = s[i-1]+a[i];
    for(int i=1;i<=n;++i){
        int l=1,r=i,mid = 1000;
        while(l < r){
            mid = l+(r-l)/2;
            if(check(mid,i)) r = mid;
            else l = mid+1;
            //cout<<mid<<' ';
        }
        //cout<<"\n\n\n";
        ans = max(ans,i-r+1);
    }
    cout<<ans;
    return 0;
}
//14:30 kai zuo!!!
//15:30 tong guo!!!(yi xiao shi zheng)
//100 pts
