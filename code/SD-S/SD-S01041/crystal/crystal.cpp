#include <bits/stdc++.h>
using namespace std;
/*====================*/
const int N=5e5+50;
long long a[N];
int ans;
/*====================*/
void Solve(void)
{
	int n;
	long long m;
	cin>>n>>m;
	__int128 lin=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	a[0]=a[1];
	for(int r=1;r<=n;r++)
	{
		lin+=(r-l)*(a[r]-a[r-1]);
		while(lin>m)
		{
			lin-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
/*====================*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) Solve();
	return 0;
}
