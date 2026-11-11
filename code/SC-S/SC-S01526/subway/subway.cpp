#include<bits/stdc++.h>
using namespace std;
const int N=400010;
int c,n,m,d,q,id[N][510],cnt[N],t[N][510];
int w[N],f[510][510];
vector <vector<int> > line;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	line.resize(n+2);
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1,k;i<=n;i++) {
		cin>>k;
		line[i].push_back(0);
		for(int j=1,a;j<=k;j++) {
			cin>>a;
			cin>>t[a][i];
			id[a][++cnt[a]]=i;
			line[i].push_back(a);
		}
	}
	for(int i=1;i<=n;i++) {
		int sz=line[i].size()-1;
		for(int j=1;j<=sz;j++) {
			for(int l=1;l<=cnt[line[i][j]];l++) {//处理f，其中cnt表示这一线上的第j站共被经过的次数
			//id[x][y]表示x号站的第y个经过的线 
				if(i==id[line[i][j]][l]) continue;
				f[i][id[line[i][j]][l]]=min(f[i][id[line[i][j]][l]],t[line[i][j]][i]+t[line[i][j]][id[line[i][j]][l]]);
				f[id[line[i][j]][l]][i]=min(f[id[line[i][j]][l]][i],t[line[i][j]][i]+t[line[i][j]][id[line[i][j]][l]]);
//				cout<<id[line[i][j]][l]<<"<->"<<i<<":"<<f[id[line[i][j]][l]][i]<<"\n";
			}
		}
	}
//	cout<<"ok\n";
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//				cout<<f[i][k]<<" "<<f[k][j]<<"\n";
			}
		}
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=n;j++) {
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1,x,y;i<=q;i++) {
		cin>>x>>y;
		int ans=INT_MAX;
		for(int j=1;j<=cnt[x];j++) {
			for(int k=1;k<=cnt[y];k++) {
//				cout<<id[x][j]<<" "<<id[y][k]<<"\n";
				ans=min(ans,f[id[x][j]][id[y][k]]+t[x][id[x][j]]+t[y][id[y][k]]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/