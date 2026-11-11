#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ma=-1e9,k;
void dfs(long long x,long long y,long long sum) {
	if(y==k) {
		ma=max(ma,sum);
		return ;
	}
	if(x==n+1)
		return ;
	dfs(x+1,y,sum);
	dfs(x+1,y+1,sum&a[x]);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	dfs(1,0,INT_MAX);
	cout<<ma<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}