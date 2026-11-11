#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll x,xl[505];
};
ll t[100005][505],ans=INT_MAX;
ll zt[100004];
vector <int> li[505];
bool pd[505];
node e[505];
ll n,m,q;
ll dfs(ll i,ll st,ll ed,ll sum,ll lx)
{
	pd[i]=true;
	ll sum2=INT_MAX;
	if(lx==1)
	{
		for(int j=0;j<li[i].size();j++)
		{
			if(li[i][j]==ed){
				sum+=t[li[i][j]][i];
				return sum;
			}
		}
		for(int j=0;j<li[i].size();j++)
		{
			sum2=min(sum2,dfs(0,li[i][j],ed,sum+t[li[i][j]][i],2));
		}
		return sum2;
	}
	else
	{
		ll x=st,sv=sum,anss=INT_MAX;
		if(st==ed)
		{
			return sum;
		}
		for(int ii=1;ii<n;ii++)
		{
			sum=sv;
			if(e[x].xl[ii]==1&&!pd[ii])
			{
				sum+=t[x][ii];
				sum+=dfs(i,0,ed,sum,1);
				anss=min(anss,sum);
			}
		}
		return anss;
	}
}
void solve(ll st,ll ed,ll sum)
{
	ll x=st,sv=sum,anss=INT_MAX;
	if(st==ed)
	{
		cout<<sum<<'\n';
		return ;
	}
	for(ll i=1;i<n;i++)
	{
		sum=sv;
		if(e[x].xl[i]==1)
		{
			sum+=t[x][i];
			sum+=dfs(i,0,ed,sum,1);
			anss=min(anss,sum);
		}
	}
	cout<<anss<<'\n';
	return ;
 } 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll hp,i,c,d,k,st,ed;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>zt[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>k;
		e[i].x=k;
		for(int j=1;j<=k;j++)
		{
			cin>>hp;
			e[i].xl[hp]=1;
			e[hp].xl[i]=1;
			li[i].push_back(hp);
			cin>>t[hp][i];
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>st>>ed;
		solve(st,ed,zt[st]+zt[ed]);
	}
	return 0;
}
