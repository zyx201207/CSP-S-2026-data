#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+8;
long long n,m,a[N];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long k = 1,sum = 0;
	long long i=1;
	while(i<n){
		if(a[i+1]-a[i]>m){
			i++;
			continue;
		}
		sum+=(a[i+1]-a[i])*k;
		if(sum>m)break;
		k++,i++;
	}
	cout << k;
	
	return 0;
} 
