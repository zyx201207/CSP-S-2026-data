#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],f[500050],s[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i < n;i++){
		f[i] = a[i+1]-a[i];
	}
	for(int i = 1;i < n;i++){
		s[i] = s[i-1] + f[i]*i;
		if(s[i] > m){
			cout<<i;
			return 0;
		}
	}
	if(s[n-1]<=m)cout << n; 
}
