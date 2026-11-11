#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end(),greater<long long>());
	long long ans=a[1];
	for(int i=2;i<=m;i++) ans=ans&a[i];
	cout<<ans;
	return 0;
}