#include<bits/stdc++.h>
using namespace std;
long long n,m,l[200005],ma=0,ans,g[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>l[1];
	ans=l[1];
	for(long long i=2;i<=n;i++){
		cin>>l[i];
		ans=ans&l[i];
		ma=max(ma,l[i]);
	}
	sort(l+1,l+1+n);
	ans=l[n-m+1];
	for(int i=n;i>=n-m+1;i--){
		ans=ans&l[i];
	}
	cout<<ans;
	return 0;
}




