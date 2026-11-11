#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500100],p[500100],l,r,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	l=1;r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		int flag=0;
		for(int i=1;i<=n-mid+1;i++){
			if(p[i+mid-1]-p[i-1]+m>=a[i+mid-1]*mid){
				flag=1;
				break;
			}
		}
		if(flag==1){
			ans=max(ans,mid);
			l=mid+1;
		}else r=mid;
	}
	cout<<ans;
	return 0;
}
