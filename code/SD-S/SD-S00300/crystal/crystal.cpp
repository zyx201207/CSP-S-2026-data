#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int sum[500005];

inline int check(int x){
	for (int r=x;r<=n;r++){
		int l=r-x+1;
		int w=sum[r]-sum[l-1];
		int lim=a[r]*x;
		if (lim-w<=m){
			return 1;
		}
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}	
	int l=1;
	int r=n;
	int ans=1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
