#include <bits/stdc++.h>
using namespace std;
int a[300000],st[300000];
int n, m;
int mx=-1;
void dfs(int u,int sum,int t)
{
	if(u==m)
	{
		if(sum>mx)mx=sum;
		return;
	}
	for(int i=t+1;i<=n;i++)
	{
		st[i]=1;
		dfs(u+1,sum&a[i],i);
		st[i]=0;
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		
		cin >> a[i];
	}
	dfs(0,-1,0);
	cout<<mx<<endl;
	
	
	return 0;
}
