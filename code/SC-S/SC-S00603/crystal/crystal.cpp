#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int s[500010];
int ans=0;
bool bread(int x){
	int ans=1e18;
	for(int i=x;i<=n;i++){
		ans=min(ans,a[i]*x-s[i]+s[i-x]);
	}
	return ans<=m;
}
void rf(int l,int r){
	if(l>r){
		return;
	}
	int mid=(l+r)>>1;
	if(bread(mid)){
		ans=max(ans,mid);
		return rf(mid+1,r);
	}
	rf(l,mid-1);
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	rf(1,n);
	cout<<ans;
	return 0;
}