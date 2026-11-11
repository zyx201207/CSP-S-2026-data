#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N];
int main() {
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout");
	long long n,m,sum=0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= m; i++){
		if(a[i] == a[i+1]){
			sum++;
		}else if(a[i] != a[i+1]){
			a[i]++;
			if(a[i] == a[i+1]){
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
} 
