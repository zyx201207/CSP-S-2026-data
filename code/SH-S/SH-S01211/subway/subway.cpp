#include<bits/stdc++.h>
using namespace std;
struct zhan{
	int kz;//地铁口到站厅
	int num;//地铁站编号 
	
};
zhan station[50001];


int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
	long long dp[50001][501]={};
	for(int i=1;i<=m;i++){
		cin>>station[i].kz; 
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>dp[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=station[x].kz+station[y].kz;
		for(int i=1;i<=n;i++){
			if(dp[i][x]!=0 && dp[i][y]!=0){//恰好一条线就可以 
				ans+=dp[i][x]+dp[i][y];
				cout<<ans<<endl;break;
			}else{
			for(int j=1;j<=m;j++){
				if(dp[i][j]!=0 && dp[i+1][j]!=0){
					ans+=dp[i][j]+dp[i+1][j];
				}
			}				
			}

		}
		cout<<ans<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
