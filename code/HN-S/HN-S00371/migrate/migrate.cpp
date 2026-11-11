#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int c,t,ans;
ll n,d;
ll pos[5005];
int dfs(ll a,ll b)
{
	int lc=0,lc1=0,lc2=0;
	int cnt=0;
	int l[100000];
	if(pos[b]-pos[a]<=d) return 0;
	for(int i=a+1;i<=b;i++)
	{
		lc1=pos[i]-pos[a];
		if(lc1>d) continue;
		else
		{
			lc2=pos[b]-pos[i];
			if(lc2<=d) lc=lc1+lc2;
			cnt++;
		}
		l[cnt]=lc;
	}
	sort(l+1,l+cnt+1);
	if(l[1]==l[2]&&(l[2]!=l[3]))
	   return 2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(pos,0,sizeof(pos));
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>pos[i];
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				int f=dfs(i,j);
				if(f==2)			
				   ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
