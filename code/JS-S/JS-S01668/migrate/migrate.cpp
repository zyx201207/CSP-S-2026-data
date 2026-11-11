#include<iostream>
#include<vector>
#include<bitset>
#define int long long
using namespace std;
int T,t,cnt;
int n,d,ans,minn;
int pos[2000005];
vector<int> g[2000005];
bitset<2000005> vis;
void pre(int s,int e){
	int ne=0;
	while(s!=e){
		for(auto v:g[s]){
			if(v>e) continue;
			ne=max(ne,v);
		}
		s=ne;
		minn++;
	}
}
void bfs(int s,int e,int l){
	if(s==e && l==minn){
		cnt++;
		return ;
	}
	for(auto v:g[s]){
		if(v>e) continue;
		bfs(v,e,l+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
			if(pos[i]-pos[i-1]>d){
				n=i-1;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(pos[j]-pos[i]>d) continue;
				g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				pre(i,j);
				bfs(i,j,0);
				if(cnt==2){
					ans++;
				}
				cnt=0;
				vis=0;
				minn=0;
			}
		}
		cout<<ans<<'\n';
		ans=0;
		for(int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
