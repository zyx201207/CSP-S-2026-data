#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ans=INT_MAX;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){	
		int opt=0;
		for(int i=1;i<=n;i++){
			ans=INT_MAX;
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				ans&=a[j];
			}
			opt=max(opt,ans);
		}
		cout<<opt;
		return 0;
	}
	if(m==2){
		int opt=0;
		for(int i=1;i<=n;i++){
			ans=0;
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				ans=max(a[j]&a[i],ans);
			}
			opt=max(opt,ans);
		}
		cout<<opt;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}