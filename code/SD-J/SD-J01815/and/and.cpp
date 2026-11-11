#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m,a[N],c[N],ma;
bool b[N];
void dfs(int x){
	if(x==m+1){
		int d=c[1];
		for(int i=2;i<=m;i++){
			d=(d&c[i]);
		}
		ma=max(ma,d);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			c[x]=a[i];
			dfs(x+1);
			c[x]=0;
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ma;
	return 0;
}
