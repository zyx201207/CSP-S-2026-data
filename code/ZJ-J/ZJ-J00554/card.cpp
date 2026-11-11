#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],dp[100005],ans[100005],d=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			for(int j=d;j>=1;j--){
				if(dp[j]==a[i]){
					d=j;
					break;
				}
			}
			dp[d]=a[i];
			d++;
		}
		while(d){
			d--;
			ans[dp[d]]++;
			dp[d]=0;
		}
		d=1;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
}

