#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	a[0] = 0;
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	long long ans = a[2] - a[1],num = 0;
	for(long long i = 1;i <= n;i++){
		b[i] = a[i - 1] + num;
		num = b[i];
	}
	for(long long i = 1;i <= n;i++){
		if(m == b[i]){
			cout << i;
			return 0;
		}else if(b[i] > m){
			cout << i - 1;
			return 0;
		}
	}
	cout << n;
	return 0;
}
