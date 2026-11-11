#include<bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
int n,m,a[500010],pr[500010];
bool ck(int x){
	for(int i=x;i<=n;i++){
		int t=pr[i]-pr[i-x];
		t=x*a[i]-t;
		if(t<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pr[i]=pr[i-1]+a[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ck(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
