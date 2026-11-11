#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500007];
long long s[500007];
long long q[500007];
long long r;
long long l;
long long maxn = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		if(i > 1) s[i - 1] = a[i] - a[i - 1];
		s[i - 1] += s[i - 2];
	}
	__int128 k = 0;
	r = 0;
	l = 0;
	for(int i = 1;i<n;i++){
		r++;
		k += (s[r] - s[r - 1])*(r - l);
		while(k > m){
			k -= (s[r] - s[l]);
			l++;
		}
		maxn = max(maxn,r - l + 1);
	}
	cout<<maxn;
	return 0;
}
