#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,m;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	} 
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while((i-j+1)*a[i]-(sum[i]-sum[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}cout<<ans;
	return 0;
}
