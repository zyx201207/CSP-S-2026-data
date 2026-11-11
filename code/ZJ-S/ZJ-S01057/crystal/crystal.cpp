#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[500010],pre[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1,j=0;i<=n;i++)
	{
		while(j<i&&1ll*(i-j)*a[i]-(pre[i]-pre[j])>m)j++;
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}