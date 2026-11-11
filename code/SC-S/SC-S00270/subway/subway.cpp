#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5,M=500005;
int c,n,m,d,q,a[N],k,b[M],bb[M],f[1001][1001];
vector<int> v[N];
void solve1(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) f[i][j]=1e14;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j]>>bb[j];
		}
		for(int j=1;j<=k;j++){
			for(int jj=1;jj<=k;jj++){
				f[b[j]][b[jj]]=min(f[b[j]][b[jj]],bb[jj]+bb[j]);
			}
		}
	}
	for(int kk=1;kk<=m;kk++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<a[x]+a[y]+f[x][y]<<'\n';
	}
}
void solve2(){
	int w;bool vis[M],flag;
	vector<int> vv[N];
	struct node{
		int x,dis;
	};
	queue<node> qq;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j]>>w;
			vv[b[j]].push_back(i);
			v[i].push_back(b[j]);
		}
	}
	int x,y;
	while(q--){
		memset(vis,false,sizeof vis);
		cin>>x>>y;
		while(!qq.empty()) qq.pop();
		qq.push({x,0});
		flag=false;
		while(!qq.empty()){
			node no=qq.front();
			qq.pop();
			for(auto i:vv[no.x]){
				for(auto j:v[i]){
					if(!vis[j]){
						vis[j]=true;
						if(j==y){
							cout<<(no.dis+1)*w+a[x]+a[y]<<'\n';
							flag=true;
							break;
						}
						qq.push({j,no.dis+1});
					}
				}
				if(flag) break;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	if(12<=c&&c<=15) solve2();
	else solve1();
}