#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long bx[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		long long ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	long long mxans;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mxans=max(a[i]&a[j],mxans);
		}
	}
	cout<<mxans;
	return 0;
} 
