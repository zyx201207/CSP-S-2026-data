#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200005];
void dfs(int i,int id,long long r)
{
	if(i>n)return ;
	if(id==m){
		ans=max(ans,r);
		return ;
	}
	if(r==-1)dfs(i+1,id+1,a[i]);
	else dfs(i+1,id+1,r&a[i+1]);
	dfs(i+1,id,r);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(1,0,-1);
		cout<<ans;
	}
	else cout<<1;
 } 
