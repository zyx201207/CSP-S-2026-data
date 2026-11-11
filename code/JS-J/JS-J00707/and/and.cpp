#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans=0;
//       weizhi    gs    he
void dfs(long long x,long long k,long long he)
{
	if(k>=m)
	{
		ans=max(ans,he);
		return;
	}
	if(x>n)
	{
		return;
	}
	dfs(x+1,k,he);
	dfs(x+1,k+1,he & a[x]);
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
	for(int i=1;i<=n;i++)
	{
		dfs(i+1,1,a[i]);
	}
	cout<<ans<<endl;
	//cout<<  (15 & 12);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
