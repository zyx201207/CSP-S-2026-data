#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+2;
long long x[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--)
	{
		int n,d,cnt=0;
		scanf("%d %d",&n,&d);
		for(int i=0;i<n;i++)
			scanf("%lld",&x[i]);
		for(int u=0;u<n-1;u++)
			for(int v=u+1;v<n;v++)
			{
				if(abs(x[v]-x[u])>d&&abs(x[v]-x[u])%d!=0&&abs(x[v]-x[u])/d>=1)
					cnt++;
			}
		cout<<cnt<<'\n';		
	}
	return 0;
}
