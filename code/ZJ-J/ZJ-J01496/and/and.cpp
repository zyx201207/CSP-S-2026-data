#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	reverse(a.begin(),a.end());
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			if((a[j+1] & a[j-1])>=(a[j] & a[j-1])) swap(a[j+1],a[j]);
		}
	}
	int sum=a[1]&a[2];
	for(int i=3;i<=m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
