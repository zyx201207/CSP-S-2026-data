//胡嘉骏 SN-J00755 陕西省西安爱知中学
#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int dp[200010];
int main(){
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		b[i]=a[i];
		for(int j=i+1;j<=m;j++){
			if(b[i]>a[j]){
				b[i]=a[j];
			}
		}
	}
	dp[1]=b[1];
	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i-1],b[i]);
	}
	cout<<dp[n-m]/2-2<<endl;
	return 0;
}
