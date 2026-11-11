#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
const ll maxm=500009;
const ll maxn=509;
ll c,n,m,d,q,kk,ans;
ll a,b;
ll w[maxm];
ll dis[maxn][maxn];
struct node{
	ll id,d;
}tmp,tmp2,tmp3;
vector<node>v[maxm];
int main()
{
	fre(subway);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=n;i++)
	{
		cin>>kk;
		for(ll j=1;j<=kk;j++)
		{
			cin>>a>>b;
			tmp.d=b;
			tmp.id=i;
			v[a].push_back(tmp);
		}
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j1=0;j1<v[i].size();j1++)
		{
			for(ll j2=j1+1;j2<v[i].size();j2++)
			{
				tmp2=v[i][j1],tmp3=v[i][j2];
				dis[tmp2.id][tmp3.id]=dis[tmp3.id][tmp2.id]=min(tmp2.d+tmp3.d,dis[tmp2.id][tmp3.id]);	
			}
		}
	}
	for(ll k=1;k<=n;k++)
	{
		dis[k][k]=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[min(i,k)][max(i,k)]+dis[min(j,k)][max(j,k)];
				}
			}
		}
	}
	while(q--)
	{
		cin>>a>>b;
		ans=1e18;
		for(ll i=0;i<v[a].size();i++)
		{
			for(ll j=0;j<v[b].size();j++)
			{
				tmp2=v[a][i];
				tmp3=v[b][j];
				ans=min(ans,dis[min(tmp2.id,tmp3.id)][max(tmp2.id,tmp3.id)]+tmp2.d+tmp3.d);
			}
		}                           
		cout<<ans+w[a]+w[b]<<"\n";
	}
	return 0;
}