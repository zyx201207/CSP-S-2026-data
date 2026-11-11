#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],qz[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(m/(i-1)<=a[i]-a[i-1]){
			ans=i-1;
			break;
		}
		if(m-(a[i]-a[i-1])*(i-1)<qz[i-1]){
			ans=i-1;
			break;
		}
		qz[i]=(a[i]-a[i-1])*(i-1)+qz[i-1];
	}
	/*int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(qz[mid]<=m){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
		
	}*/
	if(ans==0) ans=n;
	cout << ans;
	return 0;
}
//
