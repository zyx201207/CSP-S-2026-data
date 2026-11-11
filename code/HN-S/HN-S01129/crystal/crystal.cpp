#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010],m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,ans=a[1],ax=1;
	while(r<=n&&l<=r){
		while(ans+m>=a[r]*(r-l+1)&&r<=n){
			ax=max(ax,r-l+1);
			r++;
			ans+=a[r];
		}ans-=a[l];
		l++;
	}cout<<ax;
	return 0; 
}

