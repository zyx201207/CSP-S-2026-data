#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010];
int mp[510][510];
int station[510][20010];
vector<int>col[500010];
inline int find(int x,int y){
	int dist=1e18;
	for(int i:col[x]){
		for(int j:col[y]){
			dist=min(dist,mp[i][j]+station[i][x]+station[j][y]);
		}
	} 
	return dist;
} 
void solve_brute(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			station[i][aa]=tt;
			col[aa].push_back(i);
		} 
	} 
	memset(mp,0x3f,sizeof(mp));
	int inf=mp[0][0];
	for(int i=1;i<=n;i++){
		mp[i][i]=0; 
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(station[i][k]!=0&&station[j][k]!=0){
					mp[i][j]=mp[j][i]=min(mp[i][j],station[i][k]+station[j][k]);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][k]!=inf&&mp[k][j]!=inf){
					mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
				}
			}
		}
	} 
//	cout<<"mp=\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=2;j++){
//			cout<<mp[i][j]<<" ";
//		} 
//		cout<<"\n";
//	}
//	cout<<"\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+find(x,y)<<"\n";
//		cout<<w[x]<<" "<<w[y]<<" "<<find(x,y)<<"\n";
	}
}
int vis[500010][2];
void solve_2(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			vis[aa][i-1]=tt;
		} 
	} 
	int dist=1e18;
	for(int i=1;i<=n;i++){
		if(vis[i][0]!=0&&vis[i][1]!=0){
			dist=min(dist,vis[i][0]+vis[i][1]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f;
		if((vis[x][1]!=0&&vis[y][1]!=0)){
			ans=min(ans,w[x]+vis[x][1]+w[y]+vis[y][1]);
		}
		if((vis[x][0]!=0&&vis[y][0]!=0)){
			ans=min(ans,w[x]+vis[x][0]+w[y]+vis[y][0]);
		}
		int colx=(vis[x][0]!=0?0:1),coly=(vis[y][0]!=0?0:1);
		ans=min(ans,w[x]+vis[x][colx]+dist+vis[y][coly]+w[y]);
		cout<<ans<<"\n";
	} 
}
void solve_t(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			t=tt;
			col[aa].push_back(i);
		} 
	} 
	memset(mp,0x3f,sizeof(mp));
	int inf=mp[0][0];
	for(int i=1;i<=n;i++){
		mp[i][i]=0; 
		for(int j=i+1;j<=n;j++){
			mp[i][j]=mp[j][i]=t*2; 
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][k]!=inf&&mp[k][j]!=inf){
					mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
				}
			}
		}
	} 
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+find(x,y)<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c<=15){
		solve_brute();
		return 0;
	}
	if(c==20||c==21){
		solve_2();
		return 0;
	}
	if(c>=16&&c<=19){
		solve_t();
		return 0;
	} 
	return 0;
}
