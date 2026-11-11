#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],i,j;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)cin>>a[i];
	int t=n;
	while (t--){
		long long dp[500005],d[500005];
		for (i=1;i<=n;i++)dp[i]==0;
		for (i=n-t;i<=n;i++){
			if (dp[a[i]]==0){dp[a[i]]=1;d[a[i]]=i;}
			else{
				for (j=d[a[i]];j<i;j++){
					dp[a[i]]=-1,d[a[i]]=-1;
				}
				dp[a[i]]=1;
				d[a[i]]=i;
			}
		}
		for (i=1;i<=m;i++){
			if (a[i]==i&&dp[a[i]]!=-1)cout<<a[i]<<" ";
		}
	}
	return 0;
}