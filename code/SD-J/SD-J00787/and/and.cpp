#include <bits/stdc++.h>
using namespace std;
int m,n,a[200005],ma=0;
int b[200005];
bool c[200005];
int dfs(int t){
	if(t==0){
		int s=0b01111111111111111111111111111111;
		for(int i=1;i<=m;i++){
			s=s&a[b[i]];
		}
		ma=max(s,ma);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			b[t]=i;
			c[i]=1;
			dfs(t-1);
			c[i]=0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(m);
	cout<<ma;
	return 0;
}
