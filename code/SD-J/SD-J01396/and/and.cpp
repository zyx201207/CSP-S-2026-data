#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long n,m;
int sl=-10000;
void dfs(int x,int sum,int z)
{
	if(sum!=0){ z=z&a[x]; }
	sum+=1;
	if(sum==m)
	{
		sl=max(sl,z);
		return;
	}
	for(int i=x+1;i<=n;i++){ dfs(i,sum,z);}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ cin>>a[i];}
	for(int i=1;i<=n;i++){ dfs(i,0,a[i]);}
	cout<<sl;
	return 0;
}

