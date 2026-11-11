#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
const int inf=1e18+1;
int a[M],m,n,s[M];
bool check(int k){
	int res=inf;
	for(int l=1;l<=n;l++){
		int r=l+k-1;
		if(r>n){
			break;
		}
		int j=a[r]*k-(s[r]-s[l-1]);
		res=min(res,j);
	}
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
