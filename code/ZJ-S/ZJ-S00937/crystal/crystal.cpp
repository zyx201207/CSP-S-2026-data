#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;

bool check(int x){
	int s=0;
	for(int i=1;i<x;i++)s+=(a[i+1]-a[i])*i;
	for(int i=x;i<n;i++){
		if(s<=m)return true;
		s-=a[i]-a[i-x+1];
		s+=(a[i+1]-a[i])*(x-1);
	}
	if(s<=m)return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	//xiaojiguomadai,wa?xiaojiguomadai.xiaojiguomadai,wa?
	return 0;
}
