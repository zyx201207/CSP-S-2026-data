#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[5005],mp[5005][5005],dp[5005][5005],visit[5005];
long long dfs(long long st,long long end){
	if(st==end){
		return 0;
	}
	if(dp[st][end]!=0){
		return dp[st][end];
	}
	for(int i=1;i<=n;i++){
		if(mp[st][i]!=0&&visit[i]==0){
			visit[i]=1;
			if(dp[st][end]==0) return dp[st][end]=dfs(st,i)+dfs(i,end)+mp[st][i];
			else return dp[st][end]=min(dfs(st,i)+dfs(i,end)+mp[st][i],dp[st][end]);
			visit[i]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k,x[3],t[3];
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>x[j]>>t[j];
		}	
		mp[x[1]][x[2]]=t[1]+t[2];
		mp[x[2]][x[1]]=t[1]+t[2];
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		cout<<dfs(x,y)+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
