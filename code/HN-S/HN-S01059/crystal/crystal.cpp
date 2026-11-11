#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int sum[500005];
inline bool check(int x,int y){
	int tmp=a[y]*(y-x+1)-(sum[y]-sum[x-1]);
	return (tmp<=m);
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int i=1,j=0;i<=n;i++){
		while(j<n&&check(i,j+1)) j++;
		ans=max(ans,j-i+1); 
	}
	cout<<ans;
	return 0;
}
