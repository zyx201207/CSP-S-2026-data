#include<bits/stdc++.h>
#define INF (INT_MAX)
#define edgeType 
using namespace std;

int TotalTime, c;

int dfs(int now,int target,vector<vector<int> > edges){
	if((1<<now)&target) return 0;
	int ans=INF;
	for(auto item : edges[now]) ans=min(ans,dfs(item,target,edges));
	return ans+1;
}

int solution(int code,vector<vector<int> > edges,int n){ //O(N^3)
	int ans=0;
	for(int i=0;i<n;i++){
		ans=min(ans,dfs(i,code,edges));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	//code area
	cin>>c>>TotalTime;
	for(int ttt=0;ttt<TotalTime;ttt++){
		int n,k;
		cin>>n>>k;
		vector<vector<int>> edges(n+1);
		for(int i=0;i<n-1;i++){
			int from,to;
			cin>>from>>to;
			edges[from].push_back(to);
			edges[to].push_back(from);
		}
		int ans=INF;
		for(int code=0;code<(1<<k);code++){
			int cnt=0;
			for(int i=0;i<k;i++) if(code&(1<<i)) cnt++;
			if(cnt!=k) continue; 
			int nowans = solution(code,edges,n);
			if(nowans<ans) ans=nowans;
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}

