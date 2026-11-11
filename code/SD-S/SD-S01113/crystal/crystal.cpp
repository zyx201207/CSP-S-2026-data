#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum;
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0,ans=0;
	for(int i=1,j=0;i<=n;i++){
		while(j<=n&&sum<=m){
			j++;
			sum+=(j-i)*(a[j]-a[j-1]);
		}
		ans=max(ans,j-i);
		sum-=a[j]-a[i];
	}
	cout<<ans;
	return 0;
} 
