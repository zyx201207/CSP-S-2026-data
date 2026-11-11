#include <bits/stdc++.h>
using namespace std;
int main(){
		freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--);
	int n;
	long long d;
	cin>>n>>d;
	vector<long long> x(n);
	for(int i=0;i<n;i++)
	cin>>x[i];
	vector<int> nxt(n);{
	int r=0;
	for(int l=0;l<n;l++){
		if(r<l)
		r=l;
		while(r+1<n&&x[r+1]-x[l]<=d)
		r++;
		nxt[l]=r;
	}
	}
	const long long MOD=1e9+7;
	vector<int> dist(n,INT_MAX);
	vector<long long> cnt(n,0);
	dist[n-1]=0;
	cnt[n-1]=1;
	fill(dist.begin(),dist.end(),INT_MAX);
	fill(cnt.begin(),cnt.end(),0);
	dist[0]=0; cnt[0]=1;
	queue<int> q;
	q.push(0);
	vector<int> ll;
	vector<int> inll(n-1);
	inll[0]=0;
	ll.push_back({0});
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int du=dist[u];
		for(int v=u+1;v<=nxt[u]&&v<n;v++){
			if(dist[v]==INT_MAX){
				dist[v]=du+1;
				inll[v]=du+1;
				q.push(v);
			}
			if(dist[v]=du+1)
			cnt[v]=(cnt[v]+cnt[u])%MOD;
		
		}
		long long ans=0;
		for(int v=1;v<n;v++){
			if(dist[v]!=INT_MAX&&cnt[v]==2)
			ans++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
