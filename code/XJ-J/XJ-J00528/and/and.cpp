#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[100005];
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans1=a[1];
	for(int i=2;i<=n;i++){
		ans1=ans1&a[i];
	}
	if(m==n){
		cout<<ans1;
		return 0;
	}
	else if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		for(int i=n;i>=1;i--){
			for(int j=i-1;j>=1;j--){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			ans=max(ans,ans1|a[i]);
		}
	}
	else if(m==3){
		for(int i=n;i>=1;i--){
			for(int j=i-1;j>=1;j--){
				for(int k=j-1;k>=1;k--){
			
				ans=max(ans,(a[i]&a[j]&a[k]));
				}
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}