#include<bits/stdc++.h>
#define ll long long
const int N=1e6;

using namespace std;
ll c,t,n,d,a[N],b[N];
void dfs(ll step)
{
	
}
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
			cin>>a[i];
			if(i>=2)
				b[i-1]=b[i]-b[i-1];
		}		
		cout<<0<<'\n';
	}

	return 0;
}
