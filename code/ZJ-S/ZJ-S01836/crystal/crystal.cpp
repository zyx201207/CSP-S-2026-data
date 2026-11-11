#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++){
		long long l=1,r=n-i+1;
		while(l<=r){
			long long mid=l+r>>1;
			if(mid*(a[mid+i-1]-a[mid+i-2])-a[mid+i-1]+a[i-1]<=m)ans=max(ans,mid),l=mid+1;
			else r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
