#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int n,d;
int f[2000005],vis[2000005];
void dfs(int x,int y){
	for(int i=x;i<=n;i++){
		if(a[i]-a[x]<d){
			f[i]=f[x]+1;
			dfs(i,y+1);
		}
	}
}
int main(){
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out ","w",stdout);
	int c,q;
	cin>>c>>q;
	while(q--){
		memset(f,0,sizeof(f));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	return 0;
}
