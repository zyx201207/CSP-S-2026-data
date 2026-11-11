#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005],b[500005];
long long mx = LONG_LONG_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		b[i] = b[i - 1] + a[i];
	}
	long long cnt = 0;
	for(long long i = 2;i <= n;i++){
		cnt = 0;
		cnt = a[i] * (i - 1) - b[i - 1];
		if(cnt <= m){
			mx = max(mx,i);
		}
	}
	cout << mx;
	return 0;
}