//吴雨桐 西安市第六中学 SN-S00368 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1] = a[1];
	for(int i = 2;i<=n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	int maxn = 1;
	for(int i = 1;i<=n;i++){
		if(i*a[i]-sum[i] <= m){
			//cout<<a[i]<<sum[i]<<i<<endl;
			maxn = i;
		}
	}
	cout<<maxn;
	return 0;
}
