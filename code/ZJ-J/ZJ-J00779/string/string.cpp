#include<bits/stdc++.h>
using namespace std;
long long a[100100];
char c[100100];
int x(long long l,long long r ,long long z){
	if(l >=  r){
		cout << z;
		return 0;
	}
	long long f = min(a[l] , a[r]);
	a[l] -= f;
	a[r] -= f;
	if(c[l] != c[r]){
		z += f;
	}
	if(a[l] == 0){
		if(a[r] == 0){
			x(l + 1,r - 1,z);
		}else{
			x(l + 1,r,z);
		}
	}else if(a[r] == 0){
		x(l,r - 1,z);
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	long long z = 0;
	long long aa = 1;
	x(aa,n,z);
	return 0;
}
