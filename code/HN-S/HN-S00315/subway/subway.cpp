#include<bits/stdc++.h>
using namespace std;
vector<long long> v[500010];
long long c,n,m,l,d,q,ans,w[500010],a[20003][25][2];
void dfs(int s,int e,int sw,int y){
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		long long ls=0;
		cin>>l;
		for(int j=1;j<=2*l;j++){
			long long x,y;
			cin>>x>>y;
			a[x][i][0]=y;
			if(ls!=0) a[x][i][1]=ls,a[ls][i][1]=x;
			ls=x;
		}
	}
	for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			dfs(x,y,0,0);
		}
	return 0;
}
