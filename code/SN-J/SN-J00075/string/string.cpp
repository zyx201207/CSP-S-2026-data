#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len;
	int a[n],cnt=0;
	char d[n*n],c[n];
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
	}
	for(int i=0;i<n;i++){
		d[i]=c[i]*a[i];
	}
	len = n*n-1;
	for(int i=0;i<n*n;i++){
		if(d[i]!=d[len-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
