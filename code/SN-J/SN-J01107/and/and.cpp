#include<bits/stdc++.h>
using namespace std;
long long n,m,b[200005],dp[200005];
long long a[200005];
void f(int x,int sx){
	if(x==m+1){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			dp[x]=max((dp[x-1]&sx),dp[x]);
			f(x+1,a[i]);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=-1;
	}
	for(int i=1;i<=n;i++)
		dp[1]=max(dp[1],a[i]);
	f(2,dp[1]);
	cout<<dp[m];
}
