#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0,sum=0,cnt=0,pos=1;
    for(int i=1;i<=n;i++){
        sum+=cnt*(a[i]-a[i-1]),cnt++;
        while(sum>m&&pos<=i)
            sum-=a[i]-a[pos],cnt--,pos++;
        ans=max(ans,cnt);
    }
    cout<<ans;
}
/*
by GCSG01

begin: 14:50
end: 15:00
*/
/*
/usr/bin/time -f "time %e S,mxRSS %M kb" ./a
*/