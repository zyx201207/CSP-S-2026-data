#include <bits/stdc++.h>
using namespace std;
int n,m,dp[500500],c[500500],app[500500];
vector<int>num[500500];
int ans[500500];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>c[i];
	num[n].push_back(c[n]),dp[n]=n;
	for(int i=n-1;i>=1;i--){
		int len=num[i+1].size();
		for(int l=0;l<len;l++)  num[i].push_back(num[i+1][l]);
		if(app[c[i]]) continue;
		else{
			num[i].push_back(c[i]);
			app[c[i]]=1;
		}
	}
	for(int i=n-1;i<=n;i++){
		int j=c[i],k;
		for(k=i+1;c[k]!=j&&k<=n;k++){;}
		if(k<=n)  dp[i]=dp[k];
		else  dp[i]=i;
	}
	for(int i=1;i<=n;i++){
		int len=num[dp[i]].size();
		for(int j=0;j<len;j++){
			ans[num[dp[i]][j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
