# include <bits/stdc++.h>
#define ll long long
using namespace std;
const int n_max=2e6+5;
int c,t;
int n;
ll d;
ll x[n_max]={0};
bool flag[5005][5005]={0};
int dfs(int pos,int la,int h)
{
	if(pos==la) return h;
	int i;
	for(i=pos+1;i<=la;i++)
	{
		if(!flag[pos][i])
		{
			i--;
			break;
		}
	}
	cout<<pos<<endl;
	if(i==pos) return 0;
	return dfs(i,la,h+1);
}
int dfs1(int pos,int la,int h,int mi)
{
	if(pos==la)
	{
		if(h==mi) return 1;
		else return 0;
	}
	int ans=0;
	for(int i=pos+1;i<=la;i++)
	{
		if(!flag[pos][i]) break;
		ans+=dfs1(i,la,h+1,mi);
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		if(c==11 || c==12)
		{
			ll k;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
				k=x[i]-x[i-1];
			}
			ll ma=d/k;
			int ans=0;
			for(int i=ma+1;i<ma*2;i++)
			{
				ans+=(n-i+1);
			}
			cout<<ans;
		}
		else if(c<=10)
		{
			bool flag[n_max][n_max]={0};
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
				for(int j=1;j<i;j++)
				{
					if(x[i]-x[j]<=d)
					{
						flag[j][i]=true;
						flag[i][j]=true;
					}
				}
			}
			int ans=0;
			for(int u=1;u<n;u++)
			{
				for(int v=u+1;v<=n;v++)
				{
					int mi=dfs(u,v,0);
					if(mi==0) continue;
					if(dfs1(u,v,0,mi)==2) ans++;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
