#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c,m,w[50005],n,k[505],a[505][50005],t[505][50005],d,q,x,y,ans=2e9;
bool f[505][50005],ff[50005],fff[505];
void dfs(int sum,int zhan,int end) {
	if(sum>=ans)return;
	if(zhan==end){
		ans=min(ans,sum+w[end]+w[x]);
		return;
	}
	for(int i=1; i<=n; i++) {
		if(f[i][zhan]&&f[i][end]) {
//			cout<<222<<endl;
			ans=min(ans,sum+w[x]+w[end]+t[i][zhan]+t[i][end]);
//			cout<<sum+w[end]+t[i][zhan]+t[i][end]<<endl;
			return;
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<333<<endl;
		if(f[i][zhan]&&!fff[i]){
			fff[i]=1;
//			cout<<444<<endl;
			for(int j=1;j<=k[i];j++){
				if(!ff[a[i][j]]){
//					cout<<555<<endl;
					ff[a[i][j]]=1;
//					if(j==3){
//						cout<<zhan<<' '<<i<<endl;
//					}
					dfs(sum+t[i][zhan]+t[i][a[i][j]],a[i][j],end);
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j];
			f[i][a[i][j]]=1;
			cin>>t[i][a[i][j]];
		}
	}
	while(q--) {
		ans=2e9;
		memset(fff,0,sizeof(fff));
		memset(ff,0,sizeof(ff));
		bool flag=0;
		cin>>x>>y;
		for(int i=1; i<=n; i++) {
			if(f[i][x]&&f[i][y]) {
//				cout<<111<<endl<<i<<endl;
				cout<<w[x]+w[y]+t[i][x]+t[i][y]<<endl;
				flag=1;
				break;
			}
		}
		if(flag)continue;
		dfs(0,x,y);
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
