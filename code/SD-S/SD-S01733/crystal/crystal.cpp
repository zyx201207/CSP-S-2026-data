#include<bits/stdc++.h>
using namespace std;

inline long long Mmax(long long a,long long b){
	return a>b?a:b;
}

long long n,m,a[500005],s[500005],ans;

int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++)
		 s[i] = a[i] + s[i-1];
	long long l = 0 , r,mid;
	for(int i = 1; i <= n; i++){
		l = 0; r = i-1;
		while(l <= r){
			mid = l + r >> 1;
			if(mid * a[i] - (s[i-1] - s[i-mid-1]) <= m){
				ans = Mmax(ans,mid);
				l = mid + 1;
			}
			else r = mid - 1;
		}
	}
	cout << (ans+1);
	return 0;
}
