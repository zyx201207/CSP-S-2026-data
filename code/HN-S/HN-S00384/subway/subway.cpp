#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e4+10;
int f=-0x3f3f3f3f;
int l,r;
int zt[maxn];
int ans=1000000001;
vector<pair<int,int> >a[maxn];
vector<pair<int,int> >b[maxn];
void dfs(int u,int step){
	zt[u]=1;
	for(int i=0;i<b[u].size();i++){
		for(int j=0;j<a[b[u][i].first].size();j++){
			if(zt[a[b[u][i].first][j].first]==0){
				dfs(a[b[u][i].first][j].first,step+a[b[u][i].first][j].second+b[u][i].second);
			}	
		}	
		if(b[u][i].first==r){
				ans=min(step+b[u][i].second,ans);
//				cout<<step+b[u][i].second<<' '<<ans<<endl;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w1[maxn];
	for(int i=1;i<=m;i++){
		cin>>w1[i];
	} 
	int v,w;
	int o=1;
	while(n--){
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>v>>w;
			a[v].push_back({o,w});
			b[o].push_back({v,w});
		}
		o++;
	}
	while(q--){
		cin>>l>>r;
		for(int i=0;i<a[l].size();i++){
			for(int j=0;j<=o;j++){
				zt[j]=0;
			}
			dfs(a[l][i].first,0);
			ans+=a[l][i].second;
		} 
		ans+=w1[l]+w1[r]; 
		cout<<ans<<endl;
		ans=0x3f3f3f3f;
		for(int j=0;j<=o;j++){
			zt[j]=0;
		}
	}
}
