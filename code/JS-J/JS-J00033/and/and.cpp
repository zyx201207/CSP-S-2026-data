#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	int ans=a[n];
	for(int i=n;i>=n-k+1;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
