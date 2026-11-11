#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[514514],s[514514],ans=0,m;
bool check(int x,int now){
	int u=a[now]*(now-x+1);
	int sum=s[now]-s[x-1];
	if(u-sum<=m)return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,o=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i))l=mid+1;
			else r=mid-1,o=mid;
		}
		ans=max(ans,i-o+1);
	}cout<<ans<<'\n';
	return 0;
}