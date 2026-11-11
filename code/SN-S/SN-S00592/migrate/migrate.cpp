#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+114;
int n,m,c,t,d;
int a[N];
int dis[N];
int vi[N][N];
int v[N];
int f[N];
vector<int>g[N];
int dj(int st){
	memset(v,0,sizeof(v));
	memset(f,0,sizeof(f));
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	priority_queue<pair<int,int>>q;
	q.push({0,st});
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(auto y:g[x]){
			
			if(dis[y]>dis[x]+1){
//				cout<<" @@"<<x<<" "<<y<<'\n';
				dis[y]=dis[x]+1;
				f[y]=1;
				q.push({-dis[y],y});
			}else if(dis[y]==dis[x]+1){
//				cout<<" ##"<<x<<" "<<y<<'\n';
				f[y]++;
			}
		}
	}
	int re=0;
	for(int i=1;i<=n;i++){
		if(i==st)continue;
		if(f[i]==2){
//			if(vi[st][i]==0){
//				cout<<st<<" "<<i<<" "<<dis[i]<<" "<<f[i]<<'\n';
				vi[st][i]=vi[i][st]=1;
				re++;
//			}
		}
	}
	return re;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
//		memset(vi,0,sizeof(vi));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d)break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
			
		}
//		for(int i=1;i<=n;i++){
//			cout<<i<<'\n';
//			for(int j:g[i])cout<<j<<" ";
//			cout<<'\n';
//		}
		int ans=0;
		for(int i=1;i<=n;i++)ans+=dj(i);
		cout<<ans<<'\n';
	}
	//awa
	return 0;
}
//WSY
//non terrae plus ultra
