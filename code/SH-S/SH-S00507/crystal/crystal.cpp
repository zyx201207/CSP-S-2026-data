#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=0;i<=n&&j<=n;j++){
		while(i<=n&&a[i]*(i-j-1)-sum[i-1]+sum[j]<=m){
			ans=max(i-j,ans);
			sum[i]=a[i]+sum[i-1];
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
