#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500005],b[500005],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int p=i;
		for(int j=20;j>=0;j--){
			int pp=p-(1<<j);
			if(p-(1<<j)>=1){
				int sum1=(i-pp+1)*a[i],sum2=b[i]-b[pp-1];
				if(sum1-sum2<=m)p=pp;
			}
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	
	return 0;
}
