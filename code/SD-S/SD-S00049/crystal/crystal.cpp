#include<bits/stdc++.h>
using namespace std;
long long n , m , sum = 0 , maxx = 0 , a[500005] , s[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = a[i] - a[i-1];
	}
	int f = 0;
	for(int i = 3;i <= n;i++){
		if(s[i] != s[i-1]){
			f = 1;
			break;
		}
	}
	if(!f){
		long long k = a[2] - a[1];
		for(int i = 1;i <= n;i++){
			if(sum + i * k > m){
				cout << i;
				return 0;
			}
			sum += i * k;
		}
	}
	sort(a+1,a+n+1);
	for(long long i = 1;i <= n;i++){
		sum = 0;
		int f = 0;
		for(long long j = i;j >= 1;j--){
			if(sum + (a[i] - a[j]) <= m){
				sum += a[i] - a[j];
			}
			else{
				f = 1;
				maxx = max(maxx,i - j + 1);
				break;
			}
		}
		if(!f){
			maxx = max(maxx,i);
		}
	}
	cout << maxx;
	return 0;
}
