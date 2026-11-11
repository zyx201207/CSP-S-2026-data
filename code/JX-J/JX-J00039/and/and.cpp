#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	if(m==2){
		long long mx=0;
		for(int i=n-1;i>=0;i--){
			for(int j=i-1;j>=0;j--){
				long long zz=a[i]&a[j];
				mx = max(zz,mx);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		long long mx = a[0];
		for(int i=1;i<n;i++){
			mx&=a[i];
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1){
		long long mx = a[0];
		for(int i=1;i<n-5;i++){
			mx&=a[i];
		}
		int t=0;
		for(int i=n-5;i<n;i++){
			t++;
			long long xx = mx;
			for(int j=n-5;j<n;j++){
				if(j!=i)xx&=a[j];
			}
			if(t==1)mx = xx;
			else mx=max(mx,xx);
		}
		cout<<mx;
		return 0;
	}
	long long mx;
	mx = a[n-1];
	for(int i=n-2;i>=n-m;i--){
		mx&=a[i];
	}
	cout<<mx;
	return 0;
}
