#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int ans=a[n-1];
	for(int i=n-2;i>=n-m;i--) ans&=a[i];
	cout<<ans;
	return 0;
}	
