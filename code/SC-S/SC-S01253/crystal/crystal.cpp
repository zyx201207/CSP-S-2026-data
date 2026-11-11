#include <bits/stdc++.h>
using namespace std;
long long n,m,zd,zx,ans;
long long a[500010],c[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		zd=max(zd,a[i]);
		zx=min(zx,a[i]);
	}
	for(long long i=zx;i<=zd;i++){
		long long m1=m,ans1=0;
		for(long long j=1;j<=n;j++){
			c[j]=max(a[j],i)-min(a[j],i);
		}
		sort(c+1,c+1+n);
		for(long long j=1;j<=n;j++){
			if(m1>=c[j]){
				m1-=c[j];
				ans1++;
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}