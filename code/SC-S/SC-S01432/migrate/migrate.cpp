#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000010];
long long dp[505][505];
long long ans[505][505];
long long mx[505][505];
void dfs(int fx,int x,int cnt){
	//cout<<fx<<" "<<x<<" "<<cnt<<" "<<mx[fx][x]<<endl;
	if(cnt==mx[fx][x]){
		ans[fx][x]++;
	}
	if(cnt<mx[fx][x]){
		mx[fx][x]=cnt;
		ans[fx][x]=1;
	}
	for(int i=x;i<=n;i++){
		if(dp[x][i]){
			dfs(fx,i,cnt+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					dp[i][j]=1;
				} 
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mx[i][j]=1e9;
				ans[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
		//		cout<<ans[i][j]<<" ";
				if(ans[i][j]==2){
					sum++;
				} 
			}
		//	cout<<endl;
		}
		cout<<sum<<endl;
		
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/