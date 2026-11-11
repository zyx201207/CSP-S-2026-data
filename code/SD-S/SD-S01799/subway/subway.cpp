#include<bits/stdc++.h>
#define FST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ull unsigned long long
//#define ls(x)(x<<1)
//#define rs(x)(x<<1|1)
#define lowbit(x)(x&-x)
using namespace std;
const int maxn=537,maxm=5e5+37;
ll f[maxn][maxn];
ll w[maxm];int k[maxn];
int c,n,m,d,q;
vector<pair<int,ll>> jg[maxm];//经过的线 上线时间 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	FST;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f3f3f3f,sizeof(f));
//	cout<<"mx! "<<f[0][1]<<endl;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int z1;ll z2;
			cin>>z1>>z2;
			jg[z1].push_back({i,z2});
		}
		f[i][i]=0;
	}
	
	for(int i=1;i<=m;i++){
		int len=jg[i].size();
		for(int z1=0;z1<len-1;z1++){
			for(int z2=z1+1;z2<len;z2++){
				auto ed1=jg[i][z1],ed2=jg[i][z2];
				f[ed1.first][ed2.first]=min(f[ed1.first][ed2.first],ed1.second+ed2.second);
				f[ed2.first][ed1.first]=min(f[ed2.first][ed1.first],ed1.second+ed2.second);
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
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18+37;
		for(auto edx:jg[x]){
			for(auto edy:jg[y]){
				ll sum=w[x]+w[y]+edx.second+edy.second+f[edx.first][edy.first];
				ans=min(ans,sum);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


