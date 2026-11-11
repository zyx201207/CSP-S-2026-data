#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			int t=a[i]&a[j];
			ans=max(ans,t);
		}
	}
	cout<<ans;
	return 0;
}
	
