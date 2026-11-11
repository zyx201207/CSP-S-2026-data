#include<bits/stdc++.h>
#define int long long
const int M=2e6+10;
using namespace std;
int c,t;
int x[M];
int xia[M]; 
int mu=0;
int zong=0;
int lu(int a,int b)
{
	int t=a;
	int cnt=0;
	while(t<b)
	{
		if(xia[t]==t)
		{
			return -1;
		}
		t=xia[t];
		cnt++;
	}
	return cnt;
}
void dfs(int now,int step,int y)
{
	if(zong>2)
	return;
	if(step>mu)
	return;
	if(step==mu&&now==y)
	{
		zong++;
		return;
	}
	for(int i=now+1;i<=xia[now];i++)
	{
		if(i>y)
		{
			break;
		}
		dfs(i,step+1,y);
	}
}
struct node{
	int l;
	int r;
}xian[M],xxian[M];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
	int ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			xia[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		//	cout<<xia[i]<<" ";
            xian[i].l=i;
            xian[i].r=xia[i];
		}
		if(xia[xia[1]]>=n&&n>=310)
		{
		    int now=xian[1].r;
		    xxian[1].r=xian[1].r;
		    xxian[1].l=1;
		int cnt=1;
		for(int i=2;i<n;i++)
		{
		    if(now>=xian[i].r)
		    continue;
		    xxian[++cnt].l=xian[i].l;
		    xxian[cnt].r=xian[i].r;
		    now=xian[i].r;
		}
		if(cnt==1)
		{
			cout<<"0"<<endl;
			continue;
		}
		for(int i=1;i<cnt;i++)
		{
			if(xxian[i].r-xxian[i+1].l==1)
			{
				ans+=(xxian[i+1].l-xxian[i].l)*(xxian[i+1].r-xxian[i].r);
			}
		}
		cout<<ans<<endl;
		ans=0;
		continue;
		}

		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				zong=0;
				mu=lu(j,i);
				if(mu==-1)
				continue;
//				cout<<"<<"<<j<<" "<<i<<" "<<mu<<endl;
				dfs(j,0,i);
				if(zong==2)
				ans++;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}
