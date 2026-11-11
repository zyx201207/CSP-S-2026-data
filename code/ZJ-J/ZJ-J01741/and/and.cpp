#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int len;
long long a[200005];
void dfs(int x,long long sum,int y)
{
	if(y>=m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=x+1;i<n;i++)
	{
		dfs(i,a[i]&sum,y+1);
	} 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	for(int i=0;i<n;i++) dfs(i,a[i],1);
	cout<<ans<<endl;
	return 0;
}
