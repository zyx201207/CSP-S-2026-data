#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7;
int dp[10000][10000];
int a[maxn];
vector<int>ans;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
    for(int T=0;T<t;T++){
    	int n,d,cnt=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
    	for(int i=0;i<n;i++){
    		cin>>a[i];
		}
		if(abs(a[0]-a[1])<d){
			dp[0][1]=1;
		}
		else ans.push_back(0); 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(abs(a[i]-a[j])<d){
					dp[i][j]=max(dp[i][j-1]+1,dp[i][j]);
				}
				if(dp[i][j]==2){
					cnt++;
				}
			}
		}
		ans.push_back(cnt);
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
