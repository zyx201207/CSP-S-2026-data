#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,m;
ll a[N],dp[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++)dp[i]=a[1];
	for(int i=2;i<=m;i++){
		dp[i-1]=0;
		for(int j=i;j<=n;j++)
			dp[j]=max(dp[j-1],(dp[j]&a[j]));
	}
	cout<<dp[n];
}
