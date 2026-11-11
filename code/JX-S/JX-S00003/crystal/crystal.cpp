#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=n-1; i>0; i--){
		a[i]=a[i]-a[i-1];
	}
	long long total=0;
	for(int i=1; i<=n; i++){
		total+=a[i]*i;
		if(total>m){
			cout << i;
			return 0;
		}
	}
	cout << n;
}
