#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		if(m-(i-1)*(a[i]-a[i-1])<0){
			cout<<i;
			return 0;
		}
		m-=(i-1)*(a[i]-a[i-1]);
	}
	cout<<n;
	return 0;
}
