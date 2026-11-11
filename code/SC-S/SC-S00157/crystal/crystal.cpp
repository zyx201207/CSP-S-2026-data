#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,num = -10000005;
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(long long i = 1;i <= n;i++){
		long long maxsj = 1;
		for(long long j = i;j <= n;j++){
			if(a[j] + m < a[j+1])	break;
			if(a[j] + m >= a[j+1]){
				maxsj++;
				m -= a[j+1] - a[j];
			}
		}
		if(num <= maxsj){
			num = maxsj;
		}
	}
	cout << num;
	return 0;
}