#include<bits/stdc++.h>
using namespace std;

int px(long long int x, long long int y, long long int num[]){
		for(long long int j=x;j<y;j++){
			if(num[x] > num[j]) swap(num[x], num[j]);
		}
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long long int n, m;
	scanf("%lld%lld", &n, &m);
	long long int a[n];
	for(long long int i=0;i<n;i++) scanf("%lld", &a[i]);
	
	long long int iii = 0;
	while(iii < n){
		px(iii, n, a);
		iii ++;
	}
	
	long long int s = 0;
	long long int ii = n-1;
	while(ii != 0){
		for(long long int j=ii;j>=0;j--){
			s += a[ii] - a[j];
		}
		if(s <= m){
			printf("%lld", ii+1);
			break;
		}
		s = 0;
		
		ii --;
	}
	
	return 0;
}
