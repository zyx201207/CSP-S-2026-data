#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long ans=INT_MIN;
int n,m;
long long a[N];
void dfs(int k,int l,long long sum,bool flag){
	if(k>n&&l<m)
		return;
	if(l==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(flag==false)
		dfs(k+1,l+1,a[k],true);
	else dfs(k+1,l+1,sum&a[k],true);
	dfs(k+1,l,sum,flag);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0,false);
	cout<<ans;
	return 0;
}