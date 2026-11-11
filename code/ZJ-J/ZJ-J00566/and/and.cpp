#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--){
		int p;
		p=a[i]&a[i-1];
		for(int j=2;j<m;j++){
			p&=a[n-j];
		}
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}
