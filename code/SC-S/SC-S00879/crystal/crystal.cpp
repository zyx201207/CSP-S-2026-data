#include<bits/stdc++.h>
using namespace std;
long long a[500003];
long long n,m,x;
int main() {
	freopen("crystal.out","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	x=a[1]-a[0];
	long long i=1;
	while(m>x){
		m-=x*i;
		i++;
	}
	cout<<i;
	return 0;
}