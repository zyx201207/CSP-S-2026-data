#include<bits/stdc++.h>
using namespace std;
const int maxm=1e5+10;
const int maxn=5e2+10; 
int v[maxm];
int a[maxn][maxm];//先线后点；
int c,n,m,z,t; 
int line[maxn][maxn];
int low[maxn][maxn];
int k[maxn];
int top[maxn];
bool same(int x,int y){//判断起始两点是否在同一地铁线上； 
	for(int i=1;i<=top[x];i++){
		for(int j=1;j<=top[y];j++){
			if(line[x][i]==line[y][j]){
				return 1;
			}
		}
	}
	return 0;
}
void dfs(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int mini=0x3f3f3f3f;
			for(int r=1;r<=m;r++){
				if(a[j][r]==0||a[i][r]==0)continue;
				mini=min(mini,a[j][r]+a[i][r]); 
			}
			low[i][j]=mini;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>z>>t;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	memset(top,0,sizeof(top));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int cnt;
			cin>>cnt;
			cin>>a[i][cnt];
			line[cnt][++top[cnt]]=i;
		}
	}
	dfs(); 
	for(	;t>0;t--){
		int rx,ry;
		cin>>rx>>ry;
		int ans=v[rx]+v[ry];
		if(same(rx,ry)){
			cout<<ans<<endl;
		} else{
			int liit=0x3f3f3f3f;
			for(int i=1;i<=top[rx];i++){
				for(int j=1;j<=top[ry];j++){
					liit=min(liit,low[line[rx][i]][line[ry][j]]);
				}
			}
			ans+=liit;
			cout<<ans<<endl;
		}
	}
	return 0;
} 