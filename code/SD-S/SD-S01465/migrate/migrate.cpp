#include <bits/stdc++.h>
using namespace std;
long long c,t,a[20005];
long long v[10005][10005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(0));
		int n,d;
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int dis=a[2]-a[1];
		int s=d/dis;
		if(s==1||s==0)
		{
			cout<<0<<endl;
			break;
		}
		else
		{
			cout<<n-(s*2)+1<<endl;	
		}
	}
	return 0;
}
