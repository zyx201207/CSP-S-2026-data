#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],p[500005],ans;
bool check(int ll,int rr){
	//cout<<ll<<" "<<rr<<"\n";
	//cout<<(rr-ll+1)*a[rr]-(p[rr]-p[ll-1])<<'\n';
	return (rr-ll+1)*a[rr]-(p[rr]-p[ll-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	for(int i=n;i;i--){
		int l=1,r=i;
		while(l<=r){
			int mi=l+r>>1;
			if(check(i-mi+1,i))l=mi+1;
			else r=mi-1;
		}
		//cout<<r<<" ";
		ans=std::max(ans,r);
	}
	cout<<ans<<'\n';
	return 0;
}
