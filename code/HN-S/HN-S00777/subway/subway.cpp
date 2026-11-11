#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int w[N];
struct nn{
	int id,val;
};
vector<nn>vt[N];
int f[505][505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vt[a].push_back({i,t});
//			cout<<a<<"  "<<i<<"   "<<t<<"\n";
		}
	}
	for(int i=1;i<=m;i++){
//		cout<<i<<": ";
//		for(auto k:vt[i])cout<<k.id<<" ";
//		cout<<"\n";
		for(int j=0;j<vt[i].size();j++){
			nn A=vt[i][j];
			for(int k=j+1;k<vt[i].size();k++){
				nn B=vt[i][k];
//				cout<<A.id<<" "<<B.id<<" "<<A.val+B.val<<"\n";
				f[A.id][B.id]=min(f[A.id][B.id],A.val+B.val);
				f[B.id][A.id]=min(f[B.id][A.id],A.val+B.val);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			cout<<i<<"->"<<j<<" "<<f[i][j]<<"\n";
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int j=0;j<vt[x].size();j++){
			nn A=vt[x][j];
			for(int k=0;k<vt[y].size();k++){
				nn B=vt[y][k];
				ans=min(ans,A.val+B.val+f[A.id][B.id]);
//				cout<<f[A.id][B.id]<<"\n";
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
三年了，会赢的 

232  终究还是失败了吗 
*/ 
