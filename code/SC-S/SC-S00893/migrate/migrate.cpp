#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6+10;

long long N,D;

long long x[MAXN];

long long ans;

void Solve()
{
	ans=0;
	
	cin>>N>>D;
	
	for(int i=1;i<=N;i++)
	{
		cin>>x[i];
 	}
	
	for(int r=4,l=N;r<=N;r++)
	{
		if(x[r]-x[l-1]<=D)
		{
			if(x[r]-x[r-2]<=D&&x[r]-x[r-3]>D&&x[r-1]-x[r-3]<=D)
			{
				l=r-3;
			}
			
			ans+=max(0,r-2-l);
		}
		else
		{
			l=N;
		}
	}
	
	cout<<ans<<'\n';
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int c,T;
	
	cin>>c>>T;
	
	while(T--)
	{
		Solve();
	}
	
	return 0;
}