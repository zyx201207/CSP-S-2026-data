#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long num=-1;
long long a[N];
void dfs(long long shu,int ci,int shang)
{
	if(ci==m)
	{
		num=max(num,shu);
		return;
	}
	for(int i=shang+1;i<=n;i++)
	{
		long long ans=shu;
		ans&=a[i];
		dfs(ans,ci+1,i);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dfs(a[i],1,i);
	}
	cout<<num;
	return 0;
}
