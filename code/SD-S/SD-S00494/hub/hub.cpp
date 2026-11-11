#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
const int N=1e6+10;
vector<int> vt[N];
int vis[N];
int fg[N];
void dfs(int i){
	vis[i]=1;
	for(auto j:vt[i]){
		if(!vis[j]&&fg[j]) dfs(j);
	}
}
int dfs2(int i,int fa,int res,int ar){
	//cout <<i<<" ";
	if(i==ar){
		return res;
	}
	else{
		int cnt=-1;
		for(auto j:vt[i]){
			//cout <<j<<"*";
			if(j!=fa) cnt=max(cnt,dfs2(j,i,res+1,ar));
		}
		return cnt;
	}
}
void solve1(){
	while(t--){
		int n,k;
		cin >>n>>k;
		for(int i=1;i<=n;i++){
			vt[i].clear();
			vis[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin >>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		int ans=1e18;
		for(int i=0;i<(1<<n);i++){
			int flag=0;
			for(int i=1;i<=n;i++) fg[i]=0,vis[i]=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1) {
					flag++;
					fg[j+1]=1;
				}
			}
			if(flag!=k) continue;
			int cnt=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					if(!vis[j+1]){
						cnt++;
						dfs(j+1);
					}
				}
			}
			//if(i==322) cout <<cnt;
			if(cnt>2) continue;
			int tmp=0;
			for(int j=1;j<=n;j++){
				int di=1e18;
				for(int k=0;k<n;k++){
					if((i>>k)&1){
						di=min(di,dfs2(j,-1,0,k+1));
						//if(i==322)cout <<j<<" "<<k+1<<" "<<dfs2(j,-1,0,k+1)<<endl;
					}
				}
				//cout <<endl;
				tmp=max(tmp,di);
			}
			ans=min(ans,tmp);
		}
		cout <<ans<<endl;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c>>t;
	if(c<=3){
		solve1();
	}
	return 0;
}

