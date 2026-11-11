#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N];
bool check(int x){
	int res=1e18;
	for(int i=1;i+x<=n;i++){
		res=min(res,(x-1)*a[i+x-1]-pre[i+x-2]+pre[i-1]);
	}
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=0,r=N,ans=0;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1,ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}