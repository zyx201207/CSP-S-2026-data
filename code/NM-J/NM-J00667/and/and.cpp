#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[200010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=a[n];
	for(int i=n-1;i>=m;i--){
		ans+=ans&a[i];
	}
	cout<<ans;
	return 0;
}
