#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n;
long long m,a[N],ans[N],cnt=1,s;
map<long long,long long>mp1,mp2;
long long check(int x) {
	long long l = 1,r = x-1;
	while (l<r) {
		int mid = l + r + 1 >> 1;
		if (a[x]*(mid)-(ans[x-1]-ans[x-mid-1])<=m)l=mid;
		else r = mid - 1;
	}
	return l+mp1[a[x]];
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for ( int i = 1; i <= n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for ( int i = 1; i <= n;i++) {
		ans[i]=ans[i-1]+a[i];
		mp1[a[i]]++;
	}
	for (long long i = 1; i <= n;i++) {
		if(!mp2[a[i]]) {
			cnt = max(cnt,check(i));
		}
		mp2[a[i]]=1;
	} 
	cout << cnt;
	return 0;
}
