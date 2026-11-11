#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int n,m,a[N],mmax=-0x7fffffff;
int dfs(int step,int cnt,int sum)
{
	if(step==n)
	{
		if(cnt==m)
			if(mmax<sum)
				mmax=sum;
		return 0;
	}
	dfs(step+1,cnt,sum);
	if(cnt<m)
	{
		//cout<<a[step+1]<<'\n';
		dfs(step+1,cnt+1,sum&a[step+1]);
	}
	//cout<<"step"<<step<<" cnt"<<cnt<<" sum"<<sum<<"\n";
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0,0x7fffffff);
	cout<<mmax;
	return 0;
}
