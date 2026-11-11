#include<bits/stdc++.h>
using namespace std;
long long ans,ans1;
int k = 1;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long minn = 1e18;
	for(int i = 1;i<n;i++){
		b[i] = a[i+1]-a[i];
		if(b[i]<minn){
			minn = b[i];
		}
	}
	if(minn>m){
		cout<<1;
		return 0;
	}
	for(int i = 1;i<n;i++){
		long long minn = 1e18;
		for(int j = 1;j<=n-i-1;j++){
			if(k == -1){
				b[j] = a[j]+a[j+1];
				if(b[j]<minn){
					minn = b[j];
				}
			}
			else{
				a[j] = b[j]+b[j+1];
				if(a[j]<minn){
					minn = a[j];
				}
			}
		}
		k = -1*k;
		if(minn>m){
			cout<<i+1;
			return 0;
		}
	}
	return 0;
}

