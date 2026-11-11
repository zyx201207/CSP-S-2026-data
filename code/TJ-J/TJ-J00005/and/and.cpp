#include <bits/stdc++.h>
using namespace std;
long long a[2000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	long long sum=a[n-1];
	sort(a,a+n);
	for(int i=n-1;i>0;i--){
		m--;
		if(m<0) break;
		sum&=a[i];
	}
	cout << sum; 
}
