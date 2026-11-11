#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int dp[N];
int ans[M];
int lst[N],abc[M];
vector<int> e[M];

void DFS(int now,int pre){
	ans[now]=dp[now];
	for(int i=0;i<e[now].size();i++){
		int v=e[now][i];
		if(v==pre){
			continue;
		}
		DFS(v,now);
		ans[now]+=ans[v];
	}	
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(abc,-1,sizeof(abc));
	for(int i=n;i>=1;i--){
		if(abc[a[i]]==-1){
			abc[a[i]]=i;
			lst[i]=n+1;
		}else{
			lst[i]=abc[a[i]];
		}
	}
	for(int i=n;i>=1;i--){
		dp[a[i]]++;
		if(lst[i]==n+1){
			e[a[i]].push_back(a[i+1]);
			e[a[i+1]].push_back(a[i]);
		}
	}
	DFS(a[n],0);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
