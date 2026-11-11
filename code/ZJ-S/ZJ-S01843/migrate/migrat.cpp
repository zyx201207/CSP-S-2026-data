#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,x[2000005],ans,d;
int check(int u,int v)
{
	if(u==v)
		return 0;
	int ans1=check(u+1,v)+1,ans2=1;
	for(int i=u+2;i<=v;i++)
	{
		if(x[i]-x[u]<=d)
		{
			int l=check(i,v);
			if(l+1<ans1)
				ans1=l+1,ans2=1;
			else if(l+1==ans1)
				ans2++;
		}
	}
	return ans2;
}
signed main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
				if(check(i,j)==2)
					ans++;
		cout<<ans<<"\n";
	}
}
