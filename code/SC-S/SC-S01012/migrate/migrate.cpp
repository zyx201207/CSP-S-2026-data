#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//输入
	int c,t;
	int count;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int x[10005];
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		//遍历uv有双经岛屿对，有则记录
		int dp[700][700];
		for(int u=1;u<=n;u++){
			//构建数组 
			for(int v=u+1;v<=n;v++){
				if(v-u<=d){
					dp[u][v]+=1;
				}
				if(dp[u][v-1]>=1){
					dp[u][v]+=dp[u][v-1];
				}
				//判断当前是否为扫风岛屿对
				if(dp[u][v]==2){
					count++;
				} 
			}
		}
		//输出uv
		cout<<count;
	}
	 return 0;
}