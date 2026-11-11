#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0,minn=INT_MAX;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int aidelog=log2(a[i]+1);
		if(pow(2,aidelog)==a[i]+1){
			if(ans>=m){
				cout<<minn<<endl;
				return 0;
			} 
			ans++;
			minn=min(minn,a[i]);
		}
	}
	ans=a[n];
	if(m<n){
		if(m==1){
			cout<<a[n];
			return 0;
		}
		for(int i=n-1;i>=n-m+1;i--){
		   ans=ans&a[i];
	   }
	   cout<<ans<<endl;
	}else {
		for(int i=n-1;i>=1;i--)ans=ans&a[i];
		cout<<ans<<endl;
		return 0;	
	}
	return 0;
}
