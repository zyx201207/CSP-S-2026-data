#include<iostream>
using namespace std;
int n,m;
int a[200005],sum=2147483647,out; 
void dfs(int startindex,int summ)
{
	if(summ==m)
	{
		out=max(out,sum);
		//cout<<sum;
		return;
	}
	for(int i=startindex;i<n;i++)
	{
		int o=sum;
		sum=int(sum&a[i]);
		dfs(i+1,summ+1);
		sum=o;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(nullptr);
	cin>>n>>m;
	int maxx=0;
	bool isA=true;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(int(a[i]&(a[i]+1))!=0) isA=false;
	}
	if(m==1||isA)
	{
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		int ans=a[0];
		for(int i=1;i<n;i++)
		{
			ans=int(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<out;
	return 0;
}

