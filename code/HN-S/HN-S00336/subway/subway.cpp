#include<bits/stdc++.h>//16:00，估计72pts，饱含热泪 
#define int long long
using namespace std;
inline int read(){
	int x(0),sign(1);
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			sign=-1;
		}
	}
	for(;isdigit(ch);ch=getchar()){
		x=x*10+ch-'0';
	}
	return x*sign;
}
int c,n,m,d,q;
int w[500005];
vector<int> lian[500005];
vector <pair<int,int> > t[500005];//t[i]第i个地铁站连接的地铁，换乘的时间
int f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		int k(read());
		for(int j=1;j<=k;++j){
			int v(read()),tm(read());
			t[v].push_back({i,tm}); 
		}
	}
	for(int v=1;v<=m;++v){//时间复杂度O(nd^2) 500005*20*20
		for(int i=0;i<t[v].size();++i){
			for(int j=i+1;j<t[v].size();++j){
				int u1=t[v][i].first,tim1=t[v][i].second;
				int u2=t[v][j].first,tim2=t[v][j].second;
//				cout<<u1<<' '<<u2<<"连通"<<endl;
				f[u1][u2]=f[u2][u1]=min(f[u1][u2],tim1+tim2);
			}
		}
	}
	for(int i=1;i<=n;++i){
		f[i][i]=f[i][i]=0;
	}
	for(int k=1;k<=n;++k){//时间复杂度O(n^3) 500*500*500约1.2e8评测机宝宝给我过啊！！！ 
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	cout<<"距离"<<endl;
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
//		}
//	}
//	cout<<endl;
	while(q--){
		int u(read()),v(read());
		int ans=1e18;
		for(int i=0;i<t[u].size();++i){
			for(int j=0;j<t[v].size();++j){
//				cout<<t[u][i].first<<' '<<t[v][j].first<<endl;
				ans=min(ans,t[u][i].second+f[t[u][i].first][t[v][j].first]+t[v][j].second);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
} 

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
