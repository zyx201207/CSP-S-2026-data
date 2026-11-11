#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for(int i=0; i<t; i++){
		int n, d;
		cin >> n >> d;
		vector<int> pos(n+5);
		for(int j=1; j<=n; j++){
			cin >> pos[j];
		}
		stack<int> p;
		int dp[n+1][n+1];
		memset(dp, 0, sizeof(dp)); 
		p.push(1);
		int pre[n+1]={0};
		pre[1]=0;
		pre[0]=-1;
		int j=1;
		while(!p.empty()){
			j=p.top();
			p.pop();
			for(int z=j+1; z<=n; z++){
				if(pos[j]+d>=pos[z]){
					if(abs(pos[z]-pos[pre[j]])>d || j==1){
						p.push(z);
						dp[j][z]++;
						int temp=j;
						while(pre[temp]!=-1){
							dp[pre[temp]][z]++;
							temp=pre[temp];
						}
						pre[z]=j;
					}
				}
			}
		}
		int cnt=0;
		for(j=1; j<=n; j++){
			for(int z=1; z<=n; z++){
				if(dp[j][z]==2&&j!=z){
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}
