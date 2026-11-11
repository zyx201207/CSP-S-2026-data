#include<bits/stdc++.h>
using namespace std;
int n,k,f[1000010];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
bool check(int x,vector<int> e[],queue<pair<int,int>> q,bool u[]){
	int ans=n-q.size();
	bool used[n+1];
	for(int i=1;i<=n;i++) used[i]=u[i];
	while(q.size()){
		auto w=q.front();
		q.pop();
		if(w.second==x) continue;
		for(auto i:e[w.first]){
			if(!used[i]){
				q.push({i,w.second+1});
				used[i]=1;
				ans--;
			}
		}
	}
	if(ans>k) return false;
	vector<int> a;
	for(int i=1;i<=n;i++){
		f[i]=i;
		if(!used[i]) a.push_back(i);
	}
	if(a.size()<=2) return true;
	int len=a.size();
	for(auto i:a){
		for(auto j:e[i]){
			if(used[j]) continue;
			int z=find(i),y=find(j);
			if(z!=y){
				f[find(z)]=find(y);
				len--;
			}
		}
	}
	return len<=2;
}
void solve(){
	cin>>n>>k;
	vector<int> e[n+1];
	int f[n+1];
	bool used[n+1];
	memset(f,0,sizeof(f));
	memset(used,0,sizeof(used));
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		f[u]++;
		f[v]++;
	}
	queue<pair<int,int>> q;
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			used[i]=1;
			q.push({i,0});
		}
	}
	int l=0,r=n-1;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid,e,q,used)) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
}
