#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int x[2010000],dis[2010000],f[2010000];
vector<int>v[210000];
int n,d,cnt;
void bfs(int x){
	for(int i=1;i<=n;i++){
		dis[i]=-1;
		f[i]=0;
	}
	f[x]=1;
	dis[x]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		auto t=q.front(); q.pop();
		for(auto it:v[t]){
			if(dis[it]==-1){
				dis[it]=dis[t]+1;
				f[it]=f[t];
				q.push(it);
			}else if(dis[it]==dis[t]+1){
				f[it]+=f[t];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]==2)cnt++;
	}
}
void solve(int c){
	cin>>n>>d;
	cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		v[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				v[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	cout<<cnt<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve(c);
	}
	return 0;
} 
