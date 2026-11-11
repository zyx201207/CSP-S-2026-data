#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[1000050];
int sum[1000050];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int i,j;
	for(i=1,j=1;j<n;){
		if(sum[j]+(a[j+1]-a[j])*(j-i+1)<=m){
			sum[j+1]=sum[j]+(a[j+1]-a[j])*(j-i+1);
			j++;
		}else{
			sum[j]=sum[j]-(a[j]-a[i]);
			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}