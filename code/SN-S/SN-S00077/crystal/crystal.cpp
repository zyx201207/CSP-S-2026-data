#include <bits/stdc++.h>
using namespace std;
long long a[500010],pre[500010],dp[500010];
int ans[500010];
int main(){	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((max(dp[i],(a[i]*(i-j)-(pre[i-1]-pre[j-1]))))<=m){
				dp[i]=max(dp[i],(a[i]*(i-j)-(pre[i-1]-pre[j-1])));
				ans[i]=max(ans[i],(i-j+1)); 
				break;
			}
		}
	} 
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(ans[i],maxx);
	}
	cout<<maxx<<endl;
	return 0;
} 
