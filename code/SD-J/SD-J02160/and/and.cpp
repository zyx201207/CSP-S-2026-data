#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int n,a[200010],m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (m==1) {
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if (m==2){
		int Max=INT_MIN;
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				Max=max(Max,a[i]&a[j]);
			}
		}
		cout<<Max;
		return 0;
	}
	if (m==n-1){
		int Max=INT_MIN;
		for (int i=1;i<=n;i++){
			int ans=0;
			if (i==1) ans=a[2];
			else ans=a[1];
			for (int j=2;j<=n;j++){
				if (j!=i) ans&=a[j];
			}
		} 
		cout<<Max;
		return 0;
	}
	if (m==n){
		int ans=a[1];
		for (int i=2;i<=m;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	int ans=a[1];
	for (int i=2;i<=m;i++){
		ans&=a[i];
	} 
	cout<<ans;
	return 0;
}
