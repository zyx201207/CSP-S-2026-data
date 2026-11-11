#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1), s(n+1);
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a.begin()+1, a.end());
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	int ans=-1e9;
	for(int i=1;i<=n;++i){
		int val=a[i];
		int l=1, r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			int temp=s[i-1]-s[mid-1];
			int num=val*(i-mid)-temp;
			if(num<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans, i-l+1);
	}
	cout << ans << endl;
	return 0;
}