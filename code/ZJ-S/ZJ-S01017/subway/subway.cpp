#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
const int N=5e5+10;
int w[N],t[510][N],x[510][N],v[510][N];
int c,n,m,d,q;
vector<int> g2[N];
void solve1(int x,int y){
	int ans=w[x]+w[y];
	
}
void solve2(int x,int y){
	int ans=w[x]+w[y];
	cout<<ans<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		int r;
		for(int j=1;j<=k;j++){
			scanf("%lld %lld",&x[i][j],&v[i][j]);
			if(j>=2){
				g2[x[i][j]].push_back(x[i][j-1]);
				g2[x[i][j-1]].push_back(x[i][j]);
			}
			int tt=v[i][j];
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		scanf("%lld %lld",&l,&r);
		if(7<=c && c<=11){
			solve1(l,r);
		}
		if(12<=c && c<=19){
			solve2(l,r);
		}
		
	}
	return 0;
}