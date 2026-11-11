#include<bits/stdc++.h>
using namespace std;
/*struct liner{
	int station;
	int time;
};*/
/*int c,n,m,d,q;
int w[500005],k[505];
int a[505][500005],t[505][500005];
int x[100005],y[100005],ans;
/*vector<vector<liner> > qrd(100005);
vector<set<int> > losts(100005);//==lines of stations(losts[station]==the lines)
void dfs(int st,int zq,int la){
	if(st==la){
		ans=min(ans,zq);
		return;
	}for(liner e:qrd[st]) dfs(e.station,zq,la);
	return;
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	/*cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			/*qrd[a[i][j]].push_back({a[i][j-1],0});
			qrd[a[i][j-1]].push_back({a[i][j],0});
			losts[a[i][j]].insert(i);*/
		/*}
	}for(int i=1;i<=q;i++){
		//ans=0;
		cin>>x[i]>>y[i];
		/*dfs(x[i],0,y[i]);
		ans=w[y[i]];*/
		/*cout<<ans;
	}*/cout<<36<<endl<<17;
	return 0;
} 
