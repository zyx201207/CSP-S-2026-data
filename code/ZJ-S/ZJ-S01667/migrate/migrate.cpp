#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;

int n,d;
int a[N];
int ans,cnt;

void dfs(int step,int en,int sum)
{
	if(sum>cnt||step>en) return;
	if(step==en)
	{
		if(cnt>sum) cnt=sum,ans=1;
		else ans++;
		return;
	}
	for(int i=step+1;i<=en;i++)
	{
		if(a[i]-a[step]<=d) dfs(i,en,sum+1);
	}
	return;
}

bool check(int s,int t)
{
	if(a[t]-a[s]<=d) return false;
	ans=0,cnt=1e9;
	dfs(s,t,0);
	if(ans!=2) return false;
	return true;
}

void calc()
{
	bool flag1=true,flag2=true,flag3=true;
	cin>>n>>d;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag1=false;
	}
	if(flag1)
	{
		int gc=a[n]-a[n-1];
		if(d<2*gc) cout<<0<<endl;
		else if(d<3*gc) cout<<max(0*1ll,n-3)<<endl;
		else cout<<0<<endl;
		return;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bool flag=false;
		for(int j=i+1;j<=n;j++) 
		{
			if(flag&&a[j]-a[j-1]<=d&&(a[j+1]-a[j-1]>d||j==n)) ans++;
			else if(check(i,j)) ans++,flag=true;
			else flag=false;
		}
	}
	printf("%lld\n",ans);
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%lld%lld",&c,&T);
	while(T--) calc();
	return 0;
}
