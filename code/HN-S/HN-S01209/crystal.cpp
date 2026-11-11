#include<bits/stdc++.h>
using namespace std;
const long long r = 10000005;
long long n,m,k,f = 0;
long long a[r];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long i = 0;i < n;i++){
		cin>>a[i];
	}
	for(long i = 0;i < n;i++){
		if(a[i] > a[i + 1]){
			k = a[i + 1];
			a[i + 1] = a[i];
			a[i] = k;
		}
	}
	for(long i = 0;i < a[n];i++){
		a[i] -= i - a[i];
		m += (i - a[i]);
		f += 1;
		if(m < 0){
			f = 0;
			continue;
		}
	}
	f /= 2;
	cout<<f;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	return 0;
}
