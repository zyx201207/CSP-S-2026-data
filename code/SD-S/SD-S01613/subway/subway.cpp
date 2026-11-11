#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,W[500010],k[500010],D[510][510],g[3000],h[3000],G[3000],H[3000];
int minn(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
struct node{
	int A,T;
};
vector<node>f[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=500;i++){
		for(int j=0;j<=500;j++){
			D[i][j]=1e18;
		}
	}
	for(int i=1;i<=d;i++){
		D[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			f[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<f[i].size();j++){
			g[j+1]=f[i][j].A;
			h[j+1]=f[i][j].T;
		}
		int num=f[i].size();
		for(int j=1;j<=num;j++){
			for(int w=1;w<=num;w++){
				D[g[j]][g[w]]=minn(D[g[j]][g[w]],h[j]+h[w]);
			}
		}
	}
	for(int w=1;w<=n;w++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				D[i][j]=minn(D[i][w]+D[w][j],D[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<f[x].size();i++){
			g[i+1]=f[x][i].A;
			h[i+1]=f[x][i].T;
		}
		for(int i=0;i<f[y].size();i++){
			G[i+1]=f[y][i].A;
			H[i+1]=f[y][i].T;
		}
		int num=f[x].size(),numm=f[y].size();
		for(int i=1;i<=num;i++){
			for(int j=1;j<=numm;j++){
				ans=minn(ans,h[i]+H[j]+D[g[i]][G[j]]);
			//	if(ans==8){
		//			cout<<g[i]<<" "<<G[j]<<endl;
		//			return 0;
		//		}
			}
		}
		ans=ans+W[x]+W[y];
	//	if(ans==13){
	//		cout<<"hello"<<W[x]<<" "<<W[y]<<endl;
	//	}
		cout<<ans<<"\n";
	}
	return 0;
}













