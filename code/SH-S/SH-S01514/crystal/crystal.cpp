#include<bits/stdc++.h>
using namespace std;
const long long int MAXN = 5e5+10;
bool cmp(const long long &a, const long long &b){
	return a <= b;
}
int solveAB(long long n, long long m){
	long long ansAB, OverflowDays, d, Sekai;
	cin >> Sekai;
	cin >> OverflowDays;
	d = abs(Sekai-OverflowDays);
	for(int i = 3; i <= n; i++){
		cin >> OverflowDays;
		d = min(d, abs(Sekai-OverflowDays));
	}
	if (d == 0){
		cout << n;
		return n;
	}
	m = floor(m/d);
	ansAB = floor(sqrt(2*m+0.25)-0.5)+1;
	ansAB = min(ansAB,n);
	cout << ansAB << endl;
	return ansAB;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m;
	int a[MAXN];
	cin >> n >> m;
	if(n > 5000){
		solveAB(n, m);
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long size = 0, length = 1, ans = 1;
	for(int i = 1; i < n; i++){
		size += (a[i+1] - a[i])*length;
		while(size > m){
			length -= 1;
			size = size - (a[i+1] - a[i-length]);
		}
		length += 1;
		ans = max(length, ans);
	}
	cout << ans << endl;
	return 0;
} 
