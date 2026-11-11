#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,maxn;
int a[N];
int dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if (n<=20){
		int ans=0;
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		for (int i=1;i<(1<<n);i++){
			int cnt=0,sum=0;
			for (int j=0;j<n;j++){
				if (i&(1<<j)){
					if (!sum) sum=a[j];
					else sum=sum&a[j];
					cnt++;
				}
			}
			if (cnt!=m){
				continue;
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
	}
	int cnt=0;
	for (int i=1;i<=n;i++){
		if (a[i]==maxn){
			cnt++;
		}
	}
	if (cnt==m){
		cout<<maxn;
		return 0;
	}
	dp[1]=maxn;
	for (int i=1;i<=n;i++){
		if (a[i]==maxn){
			continue;
		}
		for (int j=m;j>=2;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
}
