#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,d;
	cin>>n>>d;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	for(int i=3;i<n;i++)
	{
		for(int j=1;j<i-3;j++)
		{
			if(j%2==1&&i%2==1)continue;
			ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
    return 0;#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,d;
	cin>>n>>d;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	for(int i=3;i<n;i++)
	{
		ans+=i-2;
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
    return 0;
}