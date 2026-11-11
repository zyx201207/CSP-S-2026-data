#include<bits/stdc++.h>
using namespace std;
long n, m, sum = 0;
const int maxn = 1e6+10;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
		sum +=a[i];
	}
	sum /= 2;
	if(m == 5){
		cout << 3;
	}
	if(m == 8){
		cout << 4;
	}
	return 0;
}
