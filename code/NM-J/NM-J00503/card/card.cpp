#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],dp[300010],more[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		more[dp[a[i]]]++;
		if(dp[a[i]]==i){
			ans[a[i]]+=more[i];
			more[dp[a[i+1]]]+=more[i];
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
