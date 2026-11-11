#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],ans;
void DFS(int d,int p,int q)
{
	if(d==n+1)
	{
		ans=max(ans,p*(q==m));
		return;
	}
	DFS(d+1,p&a[d],q+1);
	DFS(d+1,p,q);
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
	DFS(1,-1,0);
	cout<<ans;
	return 0; 
}
