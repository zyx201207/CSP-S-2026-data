#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,lg[1100010],ma,qian[200005],hou[20005];
void dfs(int dep,int cnt,int sum)
{
//	cout<<dep<<" "<<cnt<<" "<<sum<<endl;
	if(cnt==m)
	{
		ans=max(sum,ans);
		return;
	}
	if(dep==n+1)
	return;
	dfs(dep+1,cnt,sum);
	if(cnt==0)
	dfs(dep+1,cnt+1,a[dep]);
	else
	dfs(dep+1,cnt+1,sum&a[dep]);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=2;i<=1100000;i++)
	lg[i]=lg[i>>1]+1;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(a[i],ma);
		if(lg[a[i]]+1!=lg[a[i]+1])
		f=0;
	}
	if(f)//5pts
	{
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		ans=ans&a[i];
		cout<<ans;
	}
	else if(n<=20)//25pts
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else if(m==1)//5pts
	{
		for(int i=1;i<=n;i++)
		ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2)//15pts
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	else if(m==n)//5pts
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		ans=ans&a[i];
		cout<<ans;
	}
	else if(m==n-1)//10pts
	{
		qian[1]=a[1];
		for(int i=2;i<=n;i++)
		qian[i]=qian[i-1]&a[i];
		hou[n]=a[n];
		for(int i=n-1;i>=1;i--)
		hou[i]=hou[i+1]&a[i];
		ans=max(ans,hou[2]);
		for(int i=2;i<n;i++)
		ans=max(ans,qian[i-1]&hou[i+1]);
		ans=max(ans,qian[n-1]);
		cout<<ans;
	} 
	else//[0pts,35pts]
	{
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		ans=ans&a[i];
		cout<<ans;
	} 
	return 0;
}
