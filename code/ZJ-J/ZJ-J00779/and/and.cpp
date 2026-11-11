#include<bits/stdc++.h>
using namespace std;
long long a[200100];
long long z[200100];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1 , cmp);
	for(int i = 2;i <= n;i++){
		z[i - 1] = a[1] & a[i];
	}
	sort(z + 1,z + n , cmp);
	long int c;
	c = z[1];
	for(int i = 2;i < m;i++){
		c = c & z[i];
	}
	cout << c;
	return 0;
}
