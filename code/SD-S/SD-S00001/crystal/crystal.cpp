#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
int check(int l,int r){
	int cnt=0;
	for(int i=l;i<=r;i++){
		cnt+=a[r]-a[i];
	}
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int d=-1;
	for(int i=2;i<=n;i++){
		if(d==-1){
			d=a[i]-a[i-1];
		}
		if(d!=a[i]-a[i-1]){
			d=-1;
			break;
		}
	}
	if(d!=-1){
		int res=0;
		for(int i=1;i<=n;i++){
			int l=1,r=i,ans=0;
			while(l<=r){
				int mid=l+r>>1;
				if(d*(i-mid)*(i-mid+1)/2<=m){
					ans=mid;
					r=mid-1;
				}else l=mid+1;
			}
			res=max(res,i-ans+1);
		}
		cout<<res;
		return 0;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)){
				r=mid-1;
				ans=mid;
			}else l=mid+1;
		}
		res=max(res,i-ans+1);
	}
	cout<<res;
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
