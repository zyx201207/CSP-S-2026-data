#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[505050];
int s[505050];
bool chk(int x){
	//cout<<x<<" ";
	//连续x个能被合成同一个
	for(int r = x;r<=n;r++){
		int l=r-x+1;
		if(a[r]*x-(s[r]-s[l-1])<=m)return 1; 
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1; 
	}
	cout<<ans;
	return 0;
}
