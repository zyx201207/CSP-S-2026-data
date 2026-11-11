#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w", stdout);
	long long n,m;
	string a;
	long long cnt = 0;
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
	}
	while(m != 0){
		for(long long i = 1;i <= n;i++){
			if(a[i] != a[i+1]||a[i] != a[i-1]){
			a[i] += 1;
			m--;
			cnt++;
		}
		}
	}
	cout<<cnt;	
}
