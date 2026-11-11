#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k,sum=9999999999;
vector<int>e[1000005];
vector<int>a[1000005];
int vis[1000005];
int qq=0;
int s,cnt=0;
void dfs3(int step,int mm){
	if(vis[step]==2){
		s=step;
		cnt=mm;
		return ;
	}
	for(int i = 0;i < e[step].size();i++){
		dfs3(e[step][i],mm+1);
	}
	return ;
}
void dfs2(int step){
	if(!vis[step]){
		return ;
	}
	vis[step]=2;
	for(int i = 0;i < e[step].size();i++){
		dfs2(e[step][i]);
	}
	return ;
}
void dfs(int step,int ans){
	if(ans==k){
		qq=k;
		for(int i = 1;i <= n;i++){
			if(vis[i]){
				cnt=0;
				dfs2(i);
				vis[i]=1;
				dfs3(i,0);
				dfs3(s,0);
				qq++;
				sum=max(sum,cnt);
			}
		}
		if(qq>2){
			return ;
		}
		return ;
	}
	vis[step]=1;
	dfs(step+1,ans+1);
	vis[step]=0;
	dfs(step+1,ans);
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i < n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		cout<<sum<<"\n";
	}
	return 0;
}
