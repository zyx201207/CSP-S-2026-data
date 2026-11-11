#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int t[502][502],v[502][502],z,m,n,ans;
void dfs(int x,int va,int zz){
	if(va>=ans)return ;
	if(x==z){
		ans=min(ans,va);
		return ;
	}
	if(zz>=m)return ;
	for(int i=1;i<=t[x][0];i++){
		dfs(t[x][i],va+v[t[x][i]][i],zz+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t[i][501];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int x,y,xx,yy;cin>>x>>y>>xx>>yy;
		t[x][0]++,t[x][t[x][0]]=xx;
		v[x][t[x][0]]=y+yy;
		t[xx][0]++,t[xx][t[xx][0]]=x;
		v[xx][t[xx][0]]=y+yy;
	}
	while(q--){
		cin>>c>>z;
		ans=2e9;
		dfs(c,0,0);
		cout<<ans+t[c][501]+t[z][501]<<"\n";
	}
	return 0;
}

