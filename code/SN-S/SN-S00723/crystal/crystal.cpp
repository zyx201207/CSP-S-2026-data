#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans,b[500005];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		for(int j=i;j<=n;j++){
			b[j]=a[j]+b[j-1];
//			cout<<"    b[j]=0=0=0=0="<<b[j];
		}
//		cout<<endl;
		for(int j=i+1; j<=n; j++) {
			int cnt=(a[j]+m)/(j-i+1);
			if(cnt<a[j]-a[j-1]) {
				ans=max(ans,j-i);
				break;
			}
		}
		memset(b,0,sizeof(b));
	}
	cout<<ans;
return 0;
}
