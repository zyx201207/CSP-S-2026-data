#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,b[502][502],w[50002],a[502][50002],k[502][50002];
struct A{
	int x,y;
};
vector<A> f[50002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int kkk;
		cin>>kkk;
		for(int j=1;j<=kkk;j++){
			cin>>a[i][j]>>k[i][j];
			A ss;
			ss.x=i;
			ss.y=j;
			f[a[i][j]].push_back(ss);
		}
		a[i][0]=kkk;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=0x3f3f3f3f;
			if(i==j)b[i][i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i][0];j++){
			for(int ii=i+1;ii<=n;ii++){
				for(int jj=1;jj<=a[ii][0];jj++){
					if(a[i][j]==a[ii][jj]){
						b[i][ii]=b[ii][i]=min(b[i][ii],k[i][j]+k[ii][jj]);
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<b[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<b[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int minn=0x3f3f3f3f;
		for(int j=0;j<f[x].size();j++){
			for(int kk=0;kk<f[y].size();kk++){
				minn=min(minn,b[f[x][j].x][f[y][kk].x]+k[f[x][j].x][f[x][j].y]+k[f[y][kk].x][f[y][kk].y]);
			}
		}
		cout<<w[x]+w[y]+minn<<'\n';
	}
//	while(q--){
//		cout<<rand()%100000<<'\n';
//	}
	return 0;
}

