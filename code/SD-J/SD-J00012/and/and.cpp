#include<bits/stdc++.h>
using namespace std;
int a[200010];
int ans=0;
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int f=a[i];
		for(int j=1;j<m;j++)
		{
			f&=a[i+j];
		}
		
		ans=max(f,ans);
	}
	cout<<ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
 } 
 /*
 4 2 
 3 15 12 12
 
 */
 
