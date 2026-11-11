#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],dp[300005],b[300005],q[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		b[a[i]]=max(b[a[i]],i);
		q[i]=b[a[i]]+1;
		int x=i;
		while(x<=n) dp[a[x]]++,x=q[x];
	}
	for(int i=1;i<=m;i++) cout<<dp[i]<<" ";
	return 0;
}
