#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ttt;
int w[510000],k[510000];
int sub[510][51000],t[1000][1000];
bool b[501][510000];
int hut[510][510];//hut是地铁是否互通 
int a[510000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sub[i][j]=214748364;
			hut[i][j]=214748364;
		}
	}
	for(int p=1;p<=n;p++){
		scanf("%d",&k[p]);
//		cin>>k[p];
		for(int i=1;i<=k[p];i++){
			int a,tt;
			scanf("%d%d",&a,&tt);
//			cin>>a>>t;
			sub[p][a]=tt;//第p号地铁通往第a站的代价为tt
			b[p][a]=1;
			ttt=tt;
		}
	}

	for(int i=1;i<=n;i++){
		hut[i][i]=0;
	}

	
	if(m>400){
		for(int p=1;p<=m;p++){//对于每一个点 
			int u=1;
			for(int i=1;i<=n;i++){
				if(b[i][p]){
					a[u]=i;
					u++;
				} 
			} 
			for(int i=1;i<u;i++){
				for(int j=1;j<u;j++){
					hut[a[i]][a[j]]=min(hut[a[i]][a[j]],sub[a[i]][p]+sub[a[j]][p]);
					hut[a[j]][a[i]]=min(hut[a[j]][a[i]],sub[a[i]][p]+sub[a[j]][p]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int p=1;p<=n;p++){
					hut[j][p]=min((hut[j][i]+hut[i][p]),hut[j][p]);
					hut[p][j]=min(hut[j][p],hut[p][j]);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<hut[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
		for(int qq=1;qq<=q;qq++){
			int x,y,ans=INT_MAX,tx=0,ty=0;
			int xx[510],yy[510];
			for(int i=1;i<=n;i++){
				xx[i]=0;
				yy[i]=0;
			}
	//		cin>>x>>y;
			scanf("%d%d",&x,&y);
			for(int i=1;i<=n;i++){
				if(b[i][x]){
					tx++;
					xx[tx]=i;
				}
				if(b[i][y]){
					ty++;
					yy[ty]=i;
				}
			}
			for(int i=1;i<=tx;i++){
				for(int j=1;j<=ty;j++){
//					cout<<xx[i]<<" "<<yy[j]<<endl;
					ans=min(ans,(hut[xx[i]][yy[j]]+sub[xx[i]][x]+sub[yy[j]][y]));
				}
			}
//			cout<<ans<<" ";
			cout<<(ans+w[x]+w[y])<<endl;
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			t[i][j]=INT_MAX;
		}
	}
	

	
	
	
	
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int p=1;p<=n;p++){
				t[i][j]=min(t[i][j],(sub[p][i]+sub[p][j]));
				t[i][j]=min(t[i][j],t[j][i]);
				t[j][i]=min(t[i][j],t[j][i]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int p=1;p<=m;p++){
				t[j][p]=min((t[j][i]+t[i][p]),t[j][p]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
//		cin>>x>>y;
		scanf("%d%d",&x,&y);
		cout<<(t[x][y]+w[x]+w[y])<<endl;
	}
	return 0;
}
