#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=0;
	int ans=0;
	long long res=0;
	while(l<=r&&r<=n){
		while(res<=m&&r<=n){
			res+=(r-l)*(a[r+1]-a[r]);
			++r;
		}
		ans=max(ans,r-1-l);
		while(res>m)res-=a[r]-a[l++];
	}
	cout<<ans;
	return 0;
}
