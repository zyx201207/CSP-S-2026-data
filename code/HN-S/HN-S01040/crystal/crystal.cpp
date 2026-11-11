#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m; 
int a[500005];
int sum[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==0){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int i=n;i>1;i--){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-sum[i-1]+sum[mid-1]<=m)r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

1 2 4 1 0

8 7 5 1 0

21 13 6 1 0

17 10 4 0 0

5 8
-3 -1 2 2 7

2 3 0 5 0
10 8 5 5 0
28 18 10 5 0
*/
