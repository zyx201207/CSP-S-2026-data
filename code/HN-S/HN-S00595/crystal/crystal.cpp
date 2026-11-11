#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],pre[500010],sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
	}
	int l,r;
	l=r=1;
	ans=1;
	while(sum<=m){
		++r;
		if(r>n){
			cout<<ans<<endl;
			return 0;
		}
		sum=a[r]*(r-l)-(pre[r-1]-pre[l-1]);
		while(sum>m){
			ans=max(ans,r-l);
			++l;
			sum=a[r]*(r-l)-(pre[r-1]-pre[l]);
		}
	}
	return 0;
}

