#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],b[500010];
bool check(int mid){
	for(int l=1;l+mid-1<=n;l++){
		int r=l+mid-1;
		if(a[r]*mid-(b[r]-b[l-1])<=m){
			return 1;
		}
	}
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
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

