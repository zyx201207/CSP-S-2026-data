//100pts
#include<bits/stdc++.h>
using namespace std;
long long a[500009];
long long n,m;
bool check(int x){
	//cout<<x<<'\n';
	int l=1,r=x;
	long long nw=0;
	for(int i=l;i<=r;i++) nw+=a[r]-a[i];
	while(r<=n){
		//cout<<"³¤¶ÈÎª"<<x<<' '<<nw<<'\n';
		if(nw<=m) return true;
		nw=nw-1ll*(a[r]-a[l])+1ll*(a[r+1]-a[r])*(x-1);
		l++,r++;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	int ans;
	while(l<=r){
		int mid=(l+r)>>1;
		//cout<<"asdasd"<<mid<<'\n';
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
