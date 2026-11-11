#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+3;
int n,m;
int a[N],b[N],c[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int l=1,r=1;
	while(r<=n){
		int now=(r-l+1)*a[r]-(b[r]-b[l-1]);
		if(now<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
ez 18min AC
*/
