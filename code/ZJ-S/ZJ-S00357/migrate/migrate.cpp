//3
#include<bits/stdc++.h>
using namespace std;
int w[2100000];
const int N=0x3f3f3f3f;
int n,d,cnt=0,mn,sum;
void dfs(int x,int ans,int n)
{
	if(x>=n)
	{
		//cout<<ans<<"\n";
		if(x==n && ans==mn) sum++;
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(w[i]-w[x]>d) break;
		dfs(i,ans+1,n);
	}
	return ;
}
void f()
{
	cnt=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			sum=0;
			mn=(abs(w[j]-w[i])+d-1)/d;
			//cout<<i<<" "<<j<<" "<<mn<<"\n";
			dfs(i,0,j);
			if(sum==2) cnt++;
		}
	}
	cout<<cnt<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
		f();
	return 0;
}