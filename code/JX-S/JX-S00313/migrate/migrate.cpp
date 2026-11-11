#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N],dis[N],cnt[N],ans;
vector<signed> g[N];
void bfs(int l,int r){
	//queue<pair<int,bool>> q;
	for(int i=l;i<=r;++i){
		dis[i]=1e18+10;
		cnt[i]=0;
	}
	dis[l]=0;
	cnt[l]=1;
	queue<int> q;
	//q.push(i,true);
	q.push(l);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		/*bool flag=true;
		for(int v:g[u.first]){
			if(flag && u.second){
				q.push(make_pair(v,true));
				flag=false;
			}else{
				q.push(make_pair(v,false));
			}
			cnt[v]+=cnt[u]+
		}*/
		for(int v:g[u]){
			if(v<=r && dis[v]>=dis[u]+1){
				if(dis[v]>dis[u]+1) cnt[v]=0;
				dis[v]=dis[u]+1;
				cnt[v]+=cnt[u];
				q.push(v);
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		//init();
		for(int i=1;i<=n;++i) g[i].clear();
		for(int i=1;i<=n;++i){
			cin>>x[i];
			int j=i-1;
			while(j>=1 && x[i]-x[j]<=d){
				g[j].push_back(i);
				--j;
			}
			
		}
		for(int l=1;l<=n;++l){
			//for(int i=1;i<=n;++i) cnt[i]=0;
			for(int r=l+1;r<=n;++r){
				bfs(l,r);
				if(cnt[r]==2) ++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
* lowbit x&(-x)
* 
* inv:pow(x,mod-2)
*/
