#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+5;
int n,d,x[N],c,T,cnt,ans;
void dfs(int k,int end,int step)
{
	if(step==0)
	{
		if(k==end)
			cnt++;
	}
	if(k>=end)
		return;
	for(int i=k+1;x[i]<=x[k]+d;i++)
		dfs(i,end,step-1);
}
bool check(int st,int ed)
{
	int p=st,step=0;
	while(p<ed)
	{
		int np=(upper_bound(x+1+p,x+1+n,x[p]+d)-x)-1;//找到可以跳到的最远位置
		if(np==p)
			break;
		p=np;
		step++;
		if(p>=ed)
			break;
	}
	if(step==1)
		return 0;
	cnt=0;
	dfs(st,ed,step);
	if(cnt==2)
		return 1;
	else
		return 0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(d==1)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(check(i,j))
					ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
