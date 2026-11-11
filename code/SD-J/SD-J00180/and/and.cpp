#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e5;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			flag=0;
			break;
		}
	}
	if(m==1){
		int ans=-1e18;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxn=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		sort(a+1,a+n+1,greater<int>());
		int ans=a[1];
		for(int i=2;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(flag==1){
		sort(a+1,a+n+1,greater<int>());
		int ans=a[1];
		int k=m;
		for(int i=2;i<=n;i++){
			if(k==0){
				break;
			}
			k--;
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;	
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

