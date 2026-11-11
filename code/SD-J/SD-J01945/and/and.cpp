#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010]={};
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx<<endl;
		return 0;
	}
	if(m==2&&n<=5e4){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	int k=0;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			k=a[i];
			break;
		}
	}
	cout<<max(ans,k)<<endl;
	return 0;
}
