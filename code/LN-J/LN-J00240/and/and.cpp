#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ma=0x3f3f3f,sum=0;
void dfs(int id,int x)
{
	if(x==m){
		ma=max(ma.sum);
		return;
	}
	if(id=n+1) return;
	if(x==0) dfs(id-1,x+1);
	sum=a[id];
	else dfs(id+1,x+1);
	sum&=a[id];
	dfs(id-1,x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ma;
	return 0;
}
