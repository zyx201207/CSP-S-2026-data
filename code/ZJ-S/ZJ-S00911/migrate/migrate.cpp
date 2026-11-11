#include<bits/stdc++.h>
using namespace std;
const int slen=1e6+10;
int f[slen];int n,d;
int a[slen];
int minv=0x7f7f7f7f;
bool f2[slen];
int dfs(int node,int u,int ans)
{
	//temp=temp*10+a[node];
	if(ans>minv)	return 0;
	if(a[node]==u)
	{
		minv=min(minv,ans);
		f[ans]++;
		//cout<<endl;
		//cout<<temp<<" ";
		//cout<<ans<<endl;
		return ans;
	}
	for(int i=1;i<=n;i++)
	{
		if(f2[i]==1)	continue;
		f2[i]=1;
		if(abs(a[i]-a[node])<=d)
		{
			dfs(i,u,ans+1);
		}
		f2[i]=0;
	}
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				memset(f,0,sizeof(f));
				memset(f2,0,sizeof(f2));
				f2[i]=1;
				minv=0x7f7f7f7f;
				dfs(i,a[j],1);
				if(f[minv]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
