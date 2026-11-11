#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,m;
int a[N];
int s[N];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		int t=s[i]-(a[i]-a[i-x+1])*(i-x)-s[i-x+1];
		if(t<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) s[i]=(a[i]-a[i-1])*(i-1)+s[i-1];
	int lt=1,rt=n,ans=1;
	while(lt<=rt)
	{
		int mid=lt+rt>>1;
		if(check(mid)) lt=mid+1,ans=mid;
		else rt=mid-1;
	}
	cout<<ans;
	return 0;
}
