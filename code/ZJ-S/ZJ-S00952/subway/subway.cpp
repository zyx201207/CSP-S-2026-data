#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=5e5+7;
int c,n,m,d,q;
ll w[M];
int k[N];
int t[N][N];
ll dis[N][N];
int id[N][N];
int a[N][N];
vector<int> fath[M];
vector<int> temp;
int cnt[M];
int check(int u,int v){
	for(int i:fath[u]){
		for(int j:fath[v]){
			if(i==j) return i;
		}
	}
	return -1;
}
ll cst(int st,int mid,int ed){
	return t[st][mid]+t[ed][mid];
}
void floyd(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k:temp){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				dis[i][j]=min(dis[i][j],cst(i,k,j));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==k||i==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}		
	}
}
void solve(ll sum,int u,int v){//buzai
	ll pos=INT_MAX;
	for(int i:fath[u]){
		for(int j:fath[v]){
			pos=min(pos,t[i][u]+t[j][v]+dis[i][j]);
		}
	}
	cout<<sum+pos<<'\n';
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(t,0x3f,sizeof t);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cnt[a[i][j]]++;
			cin>>t[i][a[i][j]];
			fath[a[i][j]].push_back(i);//20yinei
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]>=2) temp.push_back(i);
	}
	floyd();
	while(q--){
		int u,v;
		cin>>u>>v;
		if(v<u) swap(u,v);
		ll ans=0;
		ans+=w[u]+w[v];
		int fa=check(u,v);
		if(fa!=-1){
			ans+=t[fa][u]+t[fa][v];
			cout<<ans<<'\n';			
		}
		else{
			solve(ans,u,v);
		}
	}
	return 0;
}
