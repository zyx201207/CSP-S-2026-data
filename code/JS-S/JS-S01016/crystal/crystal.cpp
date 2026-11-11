#include <bits/stdc++.h>
using namespace std;
long long a[600000];
long long n,m;





void sl_n2() {
	//cout<<endl<<"aaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
	sort(a,a+n);
	//int rc = -1;
	long long mx = INT64_MIN;
	for(long long i = n-1;i >= 0;--i) {
		long long l = 0;
		long long cnt = 1;
		if(i < mx){
			break;
		}
		for(int j = i-1;j >= 0;--j,++cnt) {
			l += a[i]-a[j];
			
			if(l > m) {
				l-=a[i]-a[j];
				break;
			}
		}
		if(mx < cnt) {
			 mx = cnt;
			 //rc = i;
		}
		
	}
	//cout<<"sssssssssssssss"<<endl;
	cout<<mx<<endl;
}


void sl_n1() {
	sort(a,a+n);
	//int rc = -1;
	//long long mx = INT64_MIN;
	long long l = 0;
	long long cnt = 1;
	
	for(int j = n-2;j >= 0;--j,++cnt) {
		l += a[n-1]-a[j];
		if(l > m) {
			l-=a[n-1]-a[j];
			break;
		}
	}
	cout<<cnt<<endl;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int rr = 1;
	for(long long i = 0;i < n;++i){
		cin>>a[i];
		if(i >= 2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) {
			rr = 0;
		}
	}
	if(rr&&n>100) sl_n1();
	else sl_n2();
	return 0;
}
