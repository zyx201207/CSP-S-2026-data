#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[50005],vis[50005];
bool dp[50005];
int ans=1;

vector<int> v;
int check(int k){
	int maxx=-1e9;
	for(int i=0;i<k;++i){
		maxx=max(v[i],maxx);
	}
	int x=0;
	for(int i=0;i<k;++i){
		x+=maxx-v[i];
	}
	if(x>m){
		return -1;
		
	}
	else if(x==m){
		return -2;
	}else{
		if((m-x)%k==0){
			return -2;
		}
		else{
			for(int i=2;i<=k;++i){
				if((m-x)%i==0){
					dp[i]=true;
				}
			}
			return -1;
		}
	}
	
}
void dfs(int b,int e){
	if(b==e+1){
		if(check(e)==-2){
			ans=max(ans,e);
		}
		
		return ;
	}
	for(int i=b;i<=n;++i){
		//if(i>b && a[i]==a[i-1]) continue;
		if(!vis[i]){
			vis[i]=1;
			v.push_back(a[i]);
			dfs(b+1,e);
			vis[i]=0;
			v.pop_back();
		}
	}
}
void cl(){
	while(!v.empty()){
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		if(!dp[i]){
			dfs(1,i);
		memset(vis,0,sizeof(vis));
		cl();
		}
		
		
	}
	cout<<ans;
	
	return 0;
}

