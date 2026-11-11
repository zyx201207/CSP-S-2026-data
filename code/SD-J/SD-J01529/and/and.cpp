#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long ans;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
} 
