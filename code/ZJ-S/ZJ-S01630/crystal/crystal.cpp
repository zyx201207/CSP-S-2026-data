#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,f[500010],maxs;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(f[i]-f[mid-1])<=m){
				maxs=max(maxs,(long long)i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<maxs;
	return 0;
}