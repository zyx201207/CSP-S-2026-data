#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500002];
int pre[500002];
int ans=1;
int solve(int x){
	int l=1,r=x-1,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(pre[x-1]-pre[mid-1]+m>=a[x]*(x-mid)){
			r=mid-1;
			res=mid;
		}else l=mid+1;
	}
	return x-res+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		ans=max(ans,solve(i));
	}
	cout<<ans<<"\n";
	return 0;
} 
