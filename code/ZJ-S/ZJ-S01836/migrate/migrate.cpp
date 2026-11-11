#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000100],dp[2000100];
short vis[2000100];
void bfs(int i){
	queue<int>q;
	q.push(i);
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
//		cout<<tmp<<' ';
		for(int j=tmp+1;1*a[j]-1*a[tmp]<=d&&j<=n;j++){
			
			if(vis[j]==-1||dp[j]<dp[tmp]+1)continue;//cout<<j<<' '<<dp[j]<<"    ";
			dp[j]=dp[tmp]+1;
			if(vis[j]==2){
				vis[j]=-1;
			}
			vis[j]++;
			q.push(j);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		long long sum=0;
		for(int i=n-1;i>=1;i--){
			for(int j=i;j<=n;j++)vis[j]=0,dp[j]=237489702345;
			dp[i]=0;
			bfs(i);
			for(int j=i+2;j<=n;j++){
				if(vis[j]==2)sum++;
			}
//			cout<<i<<' '<<sum<<'\n';
		}
		cout<<sum<<'\n';
	}
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
