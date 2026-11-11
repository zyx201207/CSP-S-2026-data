#include<bits/stdc++.h>
using namespace std;

namespace smilemask{
	#define rd read()
	typedef long long ll;
	const ll inf=1e18;
	inline int read(){
		int num=0,sign=1;char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') sign=-1;
			ch=getchar();
		}while(isdigit(ch)){
			num=(num<<1)+(num<<3)+ch-'0';
			ch=getchar();
		}return num*sign;
	}
	
	const int M=5e5+10;
	const int N=510;
	
	int c,n,m,d,q,w[M];
	ll f[N][N];//地铁 i 到 地铁 j 的最小值
	vector <pair<int,int>> idx[M];
	int len[N];

	void Main(){
		c=rd,n=rd,m=rd,d=rd,q=rd;
		for(int i=1;i<=m;i++) w[i]=rd;
		for(int i=1;i<=n;i++){
			len[i]=rd;
			for(int j=0;j<len[i];j++){
				int x=rd,t=rd;
				idx[x].push_back({i,t});
			}
		}
		memset(f,0x3f,sizeof f);
		for(int i=1;i<=n;i++) f[i][i]=0;
		for(int i=1;i<=m;i++){
			for(int j=0;j<idx[i].size();j++)
				for(int k=j+1;k<idx[i].size();k++)
					f[idx[i][j].first][idx[i][k].first]=min(f[idx[i][j].first][idx[i][k].first],1ll*idx[i][j].second+idx[i][k].second);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=f[j][i]=min(f[i][j],f[j][i]);
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//				if(f[i][j]<inf) cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}	
			}
		}						
		while(q--){
			int x=rd,y=rd;
			ll ans=inf;
			for(int i=0;i<idx[x].size();i++)
				for(int j=0;j<idx[y].size();j++){
//					cout<<idx[x][i].first<<' '<<idx[y][j].first<<' '<<f[idx[x][i].first][idx[y][j].first]<<endl;
					ans=min(ans,f[idx[x][i].first][idx[y][j].first]+idx[x][i].second+idx[y][j].second);
				}
			printf("%lld\n",ans+w[x]+w[y]);
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	smilemask::Main();
	return 0;
}

