#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[5010],ans,s,mn;
bool v[5010];
bool ch(int st,int ed)
{
	int la=st;
	for(int i=st;i<=ed;i++)
	{
		if(v[i]==1)
		{
			if(x[i]-x[la]>d)
			  return 0;
			else
			  la=i;
		}
	}
	return 1;
}
void dfs(int st,int ed,int nw,int sum)
{
	if(nw>ed)
	{
		if(ch(st,ed))
		{
			if(sum==mn)
			{
				s++;
			}
			if(sum<mn)
			{
				mn=sum;
				s=0;
			}
		}
		return;
	}
	if(nw!=st&&nw!=ed)
	{
		v[nw]=1;
		dfs(st,ed,nw+1,sum+1);
		v[nw]=0;
	}
	dfs(st,ed,nw+1,sum);
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		  cin>>x[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				memset(v,0,sizeof(0));
				ans=s=0;
				mn=0x3f3f3f3f;
				v[i]=v[j]=1;
				dfs(i,j,i,0);
				if(s==2)
				  ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
