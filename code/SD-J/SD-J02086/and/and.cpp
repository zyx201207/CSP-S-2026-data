#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],ans,s,t;
void dfs(int i)
{
	if(ans>=s&&t!=0) return ;
	if(t==m) ans=max(ans,s);
	if(i==n+1) return ;
	int l;
	if(t!=0) l=a[i];
	else l=0; 
	if(t==0) s=a[i];
	else s=s&&a[i]
	t++;
	dfs(i+1);
	t--;
	s=l;
	dfs(i+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
