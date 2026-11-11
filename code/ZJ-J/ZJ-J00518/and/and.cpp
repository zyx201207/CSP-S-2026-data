#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1114514],m;
int ans;
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1||m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans=ans&a[i];
			cout<<a[i]<<" ";
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int maxn=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				
				maxn=max(maxn,a[i]&a[j]);
			//	cout<<(a[i]&a[j])<<" ";
			}
		}
		cout<<maxn;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans=ans&a[i];
			cout<<a[i]<<" ";
		}
		cout<<ans;		
	}
	return 0;
}

