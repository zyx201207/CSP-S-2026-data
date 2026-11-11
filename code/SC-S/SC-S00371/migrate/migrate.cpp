#include<bits/stdc++.h>
using namespace std;
#define maxn 2000005
#define ll long long
int c,t,n;
ll d,ans,x[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(n-i>=3&&n-i%2!=0)ans+=(n-i-3)/2+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}