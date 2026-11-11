#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+3; 
int n;
long long m,a[N];
unsigned long long f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++)cin >> a[i];
	sort(a,a+n);
	f[0]=a[0];
	for(int i = 1; i < n-1; i++){
		f[i]=(a[i+1]-a[i])*2+f[i-1];
		if (m<f[i]) {
			cout << i+1;
			return 0;	
		}
	}
	cout << n;
	return 0;
}
