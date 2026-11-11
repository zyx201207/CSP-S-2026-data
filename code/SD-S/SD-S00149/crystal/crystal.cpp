#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long 
long long n,m,a[N],ans;
__int128 sum[N];
bool check(int i,int j){
	int val=a[i]*(i-j+1)-(sum[i]-sum[j-1]);
	return val<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int j=n;
	for(int i=n;i>=1;i--){
		while(j>=1&&check(i,j)){
			--j;
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
} 
