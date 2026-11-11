#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],f[500005],k,s=1,ans=1,l=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s++;
		while(k+(a[i]-a[i-1])*(i-l)>m){
			k-=a[i-1]-a[l];
			l++;
			s--;
		}k+=(a[i]-a[i-1])*(i-l);
		ans=max(ans,s);
	}cout<<ans;
	return 0;
}
