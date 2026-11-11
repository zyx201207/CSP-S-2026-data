#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],s[500010],ans,l,r,mid;
int check(int x,int y){
	if(a[y]*(y-x+1)<=s[y]-s[x-1]+m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=1;
		r=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid-1;
				ans=max(ans,i-mid+1);
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
