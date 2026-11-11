#include<bits/stdc++.h>
using namespace std;
//#define int long long
int qwe,T;
vector<int> node[100000];
int n,m,ans;
int x,y;
int v[100000];
bool f[100000];
int fin(int o){
	if(v[o]==o){
		return o;
	}
	return v[o]=fin(v[o]);
}
bool ck(){
	
	int cnt=m;
	for(int i=1;i<=n;i++){
		v[i]=i;
	}
//	cout<<cnt<<" ";
	for(int i=1;i<=n;i++){
//		cout<<f[i]<<" ";
		if(f[i]==0){
			continue;
		}
		for(int j=0;j<node[i].size();j++){
			int u=node[i][j];
			if(fin(i)!=fin(j)&&f[j]==1){
				v[fin(i)]=fin(j);
				cnt--;
			}
			if(cnt<=2){
				break;
			}
//			cout<<cnt<<" ";
		}
	}
//	cout<<cnt<<"\n";
	if(cnt<=2){
		return 1;
	}else{
		return 0;
	}
}
int bfs(){
	int w[190000];
	bool k[100000];
	queue<int> q;
//	cout<<1;
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			q.push(i);
			k[i]=1;
			w[i]=0;		
		}else{
			k[i]=0;
			w[i]=1e9;
		}
	} 
	int res=-1e9;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<node[u].size();i++){
			int b=node[u][i];
			if(k[b]==0||w[b]>w[u]+1){
				w[b]=w[u]+1;
				q.push(b);
				k[b]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<w[i]<<" "<<res<<"\n";
		res=max(res,w[i]);
	} 
	return res;
}
void dfs(int l,int r){
//	cout<<1;
	if(r>=m){
		if(ck()){
			ans=min(ans,bfs());
//			cout<<ans<<"\n";
		}
		return ;
	}
	if(l>n){
		return ;
	}
	if(n-l+1<m-r){
		return ;
	}
	f[l]=1;
	dfs(l+1,r+1);
	f[l]=0;
	dfs(l+1,r);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	cin>>qwe>>T;
	while(T--){
		ans=1e9;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			node[x].push_back(y);
			node[y].push_back(x);
		}
		dfs(1,0);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			node[i].clear();
		}
	}
}

