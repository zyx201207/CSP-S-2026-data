#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],ans=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int r=1,l=1;
	while(l<=r&&r<=n){
		while(a[r]*(r-l+1)-(b[r]-b[l-1])<=m&&r<=n){
			//cout<<l<<' '<<r<<' '<<a[r]*(r-l+1)<<' '<<(b[r]-b[l-1])<<'\n';
			ans=max(ans,r-l+1);
			r++;
		}
		//cout<<l<<' '<<r-1<<' '<<a[r-1]*(r-l)<<' '<<(b[r-1]-b[l-1])<<'\n';
		while(a[r]*(r-l+1)-(b[r]-b[l-1])>m&&l<r) l++;
		if(l==n&&r==n) break;
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?

