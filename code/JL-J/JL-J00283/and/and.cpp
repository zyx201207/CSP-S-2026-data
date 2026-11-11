#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],mx=-1e9;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else if(m==n){
		long long ans=a[1];
		for(long long i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==2){
		long long ans=-1e9;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1);
		long long ans=a[n];
		for(long long i=m;i<=n-1;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}	
	return 0;
}
