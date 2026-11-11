#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,l,r,mid,ans,ma,a[500010],s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(i=1;i<=n;i++){
		l=1,r=i,ans=i;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ma=max(ma,i-ans+1);
	}
	cout<<ma;
}
