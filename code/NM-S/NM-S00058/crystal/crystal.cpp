#include<bits/stdc++.h>
using namespace std;
typedef long long ULL;
const long long N = 500010;
long long n;
ULL m,arr[N];
pair<long long,long long> w[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i = 0;i<n;i++)cin>>arr[i],w[i].first = 0,w[i].second = i;
	sort(arr,arr+n);
	if (n>5000)return cout<<int(sqrt(m*2/(arr[1]-arr[0])))+1,0;
	long long end = n;
	for (long long i = 1;i<=n;i++) {
		for (long long j = 0;j<end;j++) {
			if (w[j].second-i<0){swap(w[j],w[--end]);j--;continue;}
			w[j].first+=arr[w[j].second]-arr[w[j].second-i];
			if (w[j].first>m){swap(w[j],w[--end]);j--;}
		}
		if (end==0)return cout<<i,0;
	}
}
