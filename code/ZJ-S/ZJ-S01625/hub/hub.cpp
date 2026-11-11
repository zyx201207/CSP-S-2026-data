#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
const int N=1e2+10;
vector<int> g[N];
vector<int> a;
bool op[N];
int qans;
bool ok(){
	vector<bool> vis(n+1,0);
	queue<int> q;
	q.push(a[0]);
	vis[a[0]]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto c:g[u]){
			if(!vis[c]){
				vis[c]=1;
				q.push(c);
			}
		}
	}
	int j=-1;
	for(auto cc:a){
		if(!vis[cc]){
			j=cc;
		}
	}
	if(j==-1){
		return 1;
	}
	q.push(j);
	vis[j]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto c:g[u]){
			if(!vis[c]){
				vis[c]=1;
				q.push(c);
			}
		}
	}
	bool oookk=1;
	for(auto cc:a){
		if(!vis[cc]){
			oookk=0;
			break;
		}
	}
	return oookk;
}
int fi(int x){
	vector<int> vvis(n+1,0);
	vvis[x]=1;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(op[c]){
//			cout<<c<<" "<<vvis[c]<<"\n";
			return vvis[c]-1;
		}
		for(auto c:g[u]){
			if(vvis[c]==0){
				vvis[c]=vvis[u]+1;
				q.push(c);
			}
		}
	}
	return -1;
}
int fff(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(op[i]!=1){
//			cout<<"%\n";
			ans=max(ans,fi(i));
		}
	}
	return ans;
}
void dfs(int d,int o){
	if(o>k) return;
	if(d>n){
		if(o!=k) return;
		if(ok()){
			qans=min(qans,fff());
//			cout<<"!\n";
			return;
		}else{
			return;
		}
	}
	a.push_back(d);
	op[d]=1;
	dfs(d+1,o+1);
	a.pop_back();
	op[d]=0;
	dfs(d+1,o);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].resize(0);
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
		}
		dfs(1,0);
		cout<<qans<<"\n";
	}
	return 0;
}
