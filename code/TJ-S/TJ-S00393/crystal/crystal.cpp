#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int a[n+1];
	long long count = 0,cmax = -1;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	long long s = 1000000000001;
	long long sql = a[2] - a[1];
	int sql1 = 1;
	for(int i = n;i >= 2;i--){
		if(a[i] - a[i-1] != sql) sql1 = 0;
	}
	if(sql1 == 1) {
		for(int i = 1;i <=n;i++){
			long long m1 = (sql + sql*i)*i/2;
			if(m >= m1) cmax = i;
			else break;
		}
		cout << cmax;
		return 0;
	}
	for(int i = n;i >= 1;i--){
		if(a[i] != s){
			long long m1 = m;
			for(int j = i;j >= 1;j--){
				long long jdz = a[i]-a[j];
				if(m1 - jdz >=0){
					count++;
					m1 -= jdz;
				}
			}
			cmax = max(cmax,count);
			count = 0;
			s = a[i];
		}
	}
	cout << cmax;
	return 0;
} 
