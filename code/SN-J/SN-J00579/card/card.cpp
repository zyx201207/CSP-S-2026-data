#include <iostream>
using namespace std;
long long k[500005];
int o(int b){
	for(long long i = 1;i<b;i++){
		if(k[i] == b){
			return i;
		}
	}
	return 0;
}
int main() {
	long long n,m;
	cin>>n>>m;
	long long a[500005];
	long long v[500005],o6[500005];
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	long long h;
	long long p;
	for(long long j =1;j<=n;j++){
		for(long long b = 1;b<=n;b++){
			k[b] = a[b];
			h = o(b);
			if(h){
				for(long long q = h;q<=b;q++){
					k[q] = -1;
				}
			}
		}
		for(long long p = 1;p<=n;p++){
			if(k[p] != -1){
				v[(j-1)*n+p] = k[p];
			}
		}
	}
	for(long long u = 0;u<500005;u++){
		o6[v[u]]+=1;
	}
	for(long long u1 = 1;u1<=m;u1++){
		cout<<o6[u1]<<' ';
	}
	return 0;
}
