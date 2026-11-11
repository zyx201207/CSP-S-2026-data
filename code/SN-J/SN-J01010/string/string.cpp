#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200001],b=0;
	char s[200001];
	cin >> n;
	for (long long i = 1 ; i <= n; i++){
		cin >> a[i];
		b+=a[i];
		cin >> s[i];
	}
	long long d=1;
	for(long long k = 1 ;k <= n ;k++){
		if(a[k] != a[k + 1]){
			d=0;
		}
	}
	if(d==1)
	cout << 0;
	else{	
	cout << b/2;
}
	return 0;	
}
	
	
