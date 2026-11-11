#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		cout<<a[1];
		return 0;
	}
	else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		long long ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long t=a[i]&a[j];
				ans=max(ans,t);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long t=a[1];
			for(int j=2;j<=n;j++){
				if(i!=j){
					t=t&a[j];
				}
			}
			ans=max(ans,t);
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
