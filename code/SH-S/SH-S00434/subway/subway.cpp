#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505];
int f[505][505];
vector<pair<int,int> > gra[505];
vector<int> num[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		int k; cin>>k;
		for(int j=1;j<=k;j++) {
			int a,ti; cin>>a>>ti;
			gra[i].push_back({a,ti});
			num[a].push_back(i);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++) {
		int len=num[i].size();
		for(int j=0;j<len;j++) {
			for(int k=j+1;k<len;k++) {
				int xi1=num[i][j],xi2=num[i][k];//线路1与线路2交叉在i号站点 
				int t1,t2,len2=gra[xi1].size(),len3=gra[xi2].size(); 
				for(int i1=0;i1<len2;i1++) {
					if(gra[xi1][i1].first==i) {
						t1=gra[xi1][i1].second;
						break;
					}
				}
				for(int i2=0;i2<len3;i2++) {
					if(gra[xi2][i2].first==i) {
						t2=gra[xi2][i2].second;
						break;
					}
				}
				f[xi1][xi2]=f[xi2][xi1]=min(t1+t2,f[xi1][xi2]);//i的xi1号线的站台->i的站厅 + i的站厅->i的xi2号线的站台 
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(f[i][j]==1061109567) {
				f[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			for(int k=1;k<=n;k++) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--) {
		int x,y,ans=2e9;
		cin>>x>>y;
		int t1,t2;
		for(int i=0;i<num[x].size();i++) {
			for(int j=0;j<num[y].size();j++) {
				int xin=num[x][i],yjn=num[y][j];
				int tmp=f[xin][yjn];
				if(tmp<ans) {
					ans=tmp;
					int xbx,xby,len1=gra[xin].size(),len2=gra[yjn].size();
					for(int t1=0;t1<len1;t1++) if(gra[xin][t1].first==x) {
						xbx=t1;
						break;
					}
					for(int t1=0;t1<len2;t1++) if(gra[yjn][t1].first==y) {
						xby=t1;
						break;
					}
					t1=gra[xin][xbx].second;t2=gra[yjn][xby].second;
				}
			}
		}
		ans+=w[x]+w[y]+t1+t2;
		cout<<ans<<'\n';
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2


//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
