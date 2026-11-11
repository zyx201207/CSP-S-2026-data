#include <bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
int n,m,a[500005],qzh[500005],ans,nxt=-inf;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	for(int i=1;i<=n;i++)
    {
        if(nxt==a[i]) continue;
        nxt=a[i];
        int tans=0,p=upper_bound(a+1,a+n+1,a[i])-a;
        tans+=p-i;
        if(i==1)
        {
            ans=max(ans,tans);
            continue;
        }
        if(i==2)
        {
            if(a[i]-a[i-1]<=m) tans++;
            ans=max(ans,tans);
            continue;
        }
        int l=1,r=i-1;
        while(l<r)
        {
            int mid=(l+r)>>1,len=i-mid;
            if(len*a[i]-(qzh[i-1]-qzh[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        tans+=i-l;
        ans=max(ans,tans);
    }
    cout<<ans;
	return 0;
 }


