#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500010],s[500010];
inline bool check(int l,int r,ll m){
	return (r-l+1)*a[r]-(s[r]-s[l-1])<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin>>n>>m;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=-1;
	for(i=1;i<=n;i++){
		int l=0,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(i,mid,m)) l=mid;
			else r=mid-1;
		}
		//printf("[%d,%d]\n",i,l);
		ans=max(l-i+1,ans);
	}
	
	cout<<ans;
	return 0;
}
