#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
vector<int> g[N];
vector<int> kk;
vector<int> kkk;
bool ok[N];
bool state[N];
int n,k;
int ans=1e9;
void goes(int x){  //遍历 
	ok[x]=true;
	for(int i:g[x]){
		if(!ok[i]) goes(i);
	}
}
bool check(){  //合法方案 
	int cnt=0;
	for(int i:kkk){
		bool tf=true;
		goes(i);
		for(int j=1;j<=n;j++){
			if(!ok[j]){
				tf=false;
				break;
			}
		}
		if(tf) cnt++;  //连通块 
		memset(ok,false,sizeof ok);
	}
	return (cnt<=2);
}
bool ffind(int x){
	for(int i:kkk) if(i==x) return true;
	return false;
}
int dd=1e9;
void dist(int x,int step){
	if(ffind(x) && dd!=0){  //到达基地 
		dd=min(dd,step);
		return;
	}
	state[x]=true;
	for(int i:g[x]){
		if(!state[i]) dist(i,step+1);
	}
}
void solve(){
	if(check()){  //合法方案 
		int s=0;
		for(int i=1;i<=n;i++){
			if(!ffind(i)){
				dist(i,0);  //通勤距离 
				memset(state,false,sizeof state);
				s=max(s,dd);
				dd=1e9;
			}
			
		}
		ans=min(ans,s);
	}
}
void dfs(int x,int num){  //选 
	if(x==n+2) return;
	if(num==k){
		kkk=kk;
		solve();
		return;
	}
	kk.push_back(x);
	dfs(x+1,num+1);
	kk.pop_back();
	dfs(x+1,num);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);	
		if(ans==1e9) cout<<2<<"\n";	
		else cout<<ans<<"\n";
		ans=1e9;
		dd=1e9;
		for(int i=1;i<=n;i++) g[i].clear();
		kk.clear();
		kkk.clear();
	}
	return 0;
}


