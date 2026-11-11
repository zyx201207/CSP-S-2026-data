#include <bits/stdc++.h>
#define int long long
#define ret return
#define mid (l+r>>1)
using namespace std;
#define pb push_back
#define mp make_pair
int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	ret s*f;
}
const int M=5e5+10,N=510,Mod=998244353,INF=1e18;
int c[M],dis[N][N];
vector<pair<int,int>> sub[M];
vector<pair<int,int>> v[N];
void solve(){
	int id=read(),n=read(),m=read(),d=read(),ask=read();
	for(int i=1;i<=m;i++)c[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int x=read(),y=read();
			sub[x].pb(mp(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<sub[i].size();j++){
			for(int k=j+1;k<sub[i].size();k++){
				int val=sub[i][j].second+sub[i][k].second;
				v[sub[i][j].first].pb(mp(sub[i][k].first,val));
				v[sub[i][k].first].pb(mp(sub[i][j].first,val));
			}
		}
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	memset(dis,-1,sizeof(dis));
	for(int i=1;i<=n;i++){
		q.push(mp(0,i));
		while(!q.empty()){
			pair<int,int> d=q.top();q.pop();
			if(dis[i][d.second]!=-1)continue;
			dis[i][d.second]=d.first;
			for(auto j:v[d.second]){
				if(dis[i][j.first]!=-1)continue;
				q.push(mp(d.first+j.second,j.first));
			}
		}
	}
	while(ask--){
		int x=read(),y=read(),minn=INF;
		for(auto i:sub[x])for(auto j:sub[y])
		minn=min(minn,dis[i.first][j.first]+i.second+j.second);
		printf("%lld\n",minn+c[x]+c[y]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t=1;while(t--)solve();
	ret 0;
}
