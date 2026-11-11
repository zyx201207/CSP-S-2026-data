#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m
	vector<ll> a(n+1),cnt(35);
	vector<string> s(n+1); 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll res=a[n];
	for(int i=n-1,j=2;j<=m;i--,j++){
		res&=a[i];
	}
	cout<<res;
	return 0;
}
