#include<bits/stdc++.h>
#define int long long
using namespace std;const int N=4e3+5,inf=1e18;
int n,m,k,sz[N],f[N][N][2][3];vector<int> v[N];
inline void clear(int f[N][2][3]){for(int i=0;i<=k;i++)for(int j=0;j<2;j++)for(int k=0;k<3;k++)f[i][j][k]=inf;}
inline void chkmin(int &x,int y){x=min(x,y);}
inline void dfs(int x,int fa){
	if(!(v[x].size()-(fa>0))){clear(f[x]),f[x][0][0][0]=m+1,f[x][1][1][1]=0,sz[x]=1;return;}
	clear(f[x]),f[x][0][0][0]=f[x][1][1][1]=0,sz[x]=1;int g[N][2][3];
	for(int t:v[x])if(t!=fa){
		dfs(t,x),clear(g);
		for(int j1=0;j1<=min(sz[x],k);j1++)for(int k1=0;k1<2;k1++)for(int l1=0;l1<3;l1++){
			for(int j2=0;j2<=min(sz[t],k-j1);j2++)for(int k2=0;k2<2;k2++)for(int l2=0;l2<3;l2++){
				int L=l1+l2-(k1&&k2),w1=f[x][j1][k1][l1],w2=f[t][j2][k2][l2]+1;
//				if(x==1){
//					cout<<x<<" "<<t<<"   "<<j1<<" "<<k1<<" "<<l1<<"    "<<j2<<" "<<k2<<" "<<l2<<"   "<<w1<<" "<<w2<<"\n";
//				}
				if(L>2||((l1||l2)?w1+w2:max(w1,w2))>2*m+1)continue;
				int D=(k1?0:(((l1&&l2)||(!l1&&!l2))?max(w1,w2):(l1?w1:w2)));chkmin(g[j1+j2][k1][L],D);
//				if(x==1)cout<<"###### "<<j1+j2<<" "<<k1<<" "<<L<<" "<<D<<"\n";
			}
		}
		sz[x]+=sz[t];
		for(int i=0;i<=min(sz[x],k);i++)for(int j=0;j<2;j++)for(int k=0;k<3;k++)f[x][i][j][k]=g[i][j][k];
//		cout<<"after "<<x<<"->"<<t<<":\n";
		for(int i=0;i<=min(sz[x],k);i++){
			int ans=inf;
			for(int j=0;j<2;j++)for(int k=0;k<3;k++)ans=min(ans,f[x][i][j][k]);
//			cout<<i<<" "<<ans<<"     ";
		}
//		cout<<"\n\n";
	}
//	cout<<x<<":\n";
//	for(int i=0;i<=min(sz[x],k);i++){
//		int ans=inf;
//		for(int j=0;j<2;j++)for(int k=0;k<3;k++)ans=min(ans,f[x][i][j][k]);
//		cout<<i<<" "<<ans<<"     ";
//	}
//	cout<<"\n";
}
inline bool check(int _m){
//	cout<<"check "<<_m<<"\n";
	m=_m,dfs(1,0);int ans=inf;
	for(int l=0;l<=k;l++)for(int i=0;i<2;i++)for(int j=0;j<3;j++)ans=min(ans,f[1][l][i][j]+(!i)*(m+1));
//	cout<<"AAAAAA     "<<m<<" "<<ans<<"\n\n\n\n";
	return ans<=2*m+1;
}
signed main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _c,_T;cin>>_c>>_T;
	while(_T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1,x,y;i<n;i++)cin>>x>>y,v[x].emplace_back(y),v[y].emplace_back(x);
//		cout<<check(100)<<"\n";
//		continue;
		int L=0,R=n-1;
		while(L<R){int mid=(L+R)>>1;(check(mid)?R=mid:L=mid+1);}
		cout<<L<<"\n";
	}
	return 0;
}