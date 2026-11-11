#include<bits/stdc++.h>
using namespace std;
long long n;
long long a1[200005];
long long sum,l,r,m;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(long long i = 1;i <= n;++i){
		cin >> a1[i] >> c[i];
		m++;
	}
	l = 1;
	r = m;
	if(n == 1 || n == 0){
		cout << 0;
		return 0;
	}
	while(l < r){
		if(c[l] == c[r]){
			if(a1[l] < a1[r]){
				a1[r] -= a1[l];
				l++;
			}else if(a1[l] > a1[r]){
				a1[l] -= a1[r];
				r--;
			}else{
				l++;
				r--;
			}
		}else{
			if(a1[l] < a1[r]){
				sum += a1[l];
				a1[r] -= a1[l];
				l++;
			}else if(a1[l] > a1[r]){
				sum += a1[r];
				a1[l] -= a1[r];
				r--;
			}else{
				sum += a1[l];
				l++;
				r--;
			}
		}
	}
	cout << sum;
	
	
	return 0;
}

