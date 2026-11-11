#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],stt[500005];
bool check(int mmm){
	for(int l=1;l+mmm<=n+1;l++){
		int r=l+mmm-1;
		if(mmm*a[r]-stt[r]+stt[l-1]<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		stt[i]=stt[i-1]+a[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)==1){
			l=mid+1;
			ans=mid;
		}
		else if(check(mid)==0){
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
