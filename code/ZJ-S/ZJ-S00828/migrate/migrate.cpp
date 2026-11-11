#include<bits/stdc++.h>
using namespace std;
const int inf=5000005;
int c,t;
int n,m;
int x[inf];
int d[inf];
int ans;
void dfs(int x,int y,int step,int cnt){
	if(x==y){
		ans=min(ans,step);
		return;
	}
	int s=m;
	int v=x;
	while(s>0){
		int a=d[v];
		if(s-a>0){
			dfs(x++,y,step+d[v],cnt);
			v++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			d[i]=d[i]-d[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int ans=0x3f3f3f;
				dfs(i,j,0,0);
			}
		}
	}
	return 0;
}