#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500005;
int n;
ll m,a[N],lg[N],st[22][N],sum[N];
ll rmq(ll l,ll r){
	int t=lg[r-l+1];
	return max(st[t][l],st[t][r-(1<<t)+1]);
}
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		ll cost=rmq(i,i+x-1)*x-(sum[i+x-1]-sum[i-1]);
		if(cost<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	lg[1]=0;
	for(int i=2;i<=n;i++)lg[i]=lg[i/2];
	for(int i=1;i<=n;i++){
		st[0][i]=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int j=1;j<=lg[n];j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
	
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
// mx*i-sum<=m 
/*
freopen 文件名 调试信息 数据范围
*/

