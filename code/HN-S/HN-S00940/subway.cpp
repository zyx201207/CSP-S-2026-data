#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
namespace IO{
	char *p1,*p2,buf[100000];
	#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
	template<class T>
	inline void read(T &x){
		int f=1,ch=nc();x=0;
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=nc();
		}
		while(isdigit(ch)){
			x=(x<<3)+(x<<1)+ch-'0';
			ch=nc();
		}
		x*=f;
	}
	template<class T>
	void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
};
using namespace IO;
constexpr int N=505,M=500005,INF=LLONG_MAX;
int C,n,m,d,q,k,a,b,t,w[M],dis[N][N];
vector<pair<int,int> > vis[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(C),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++){
		read(w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		read(k);
		for(int j=1;j<=k;j++){
			read(a),read(t);
			vis[a].push_back({i,t});
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto x:vis[i]){
			for(auto y:vis[i]){
				int X=x.first,Y=y.first,Xt=x.second,Yt=y.second; 
				dis[X][Y]=min(dis[X][Y],Xt+Yt);
//				cout<<X<<" -> "<<Y<<" "<<Xt+Yt<<endl;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]==INF||dis[k][j]==INF) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<"dis "<<i<<","<<j<<"= "<<dis[i][j]<<endl;
//		}
//	}
	while(q--){
		read(a),read(b);
		int ans=INF;
		for(auto x:vis[a]){
			for(auto y:vis[b]){
				int X=x.first,Y=y.first,Xt=x.second,Yt=y.second;
				if(dis[X][Y]==INF) continue;
				ans=min(ans,Xt+Yt+dis[X][Y]);
			}
		}
		write(ans+w[a]+w[b]);
		puts("");
	}
}

