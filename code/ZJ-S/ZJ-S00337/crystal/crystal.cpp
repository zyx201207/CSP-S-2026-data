#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e6+10;
int n,m,a[N];
bool check(int x){
	int sum=0;
	for(int i=n;i>=n-x+1;i--) sum+=a[n]-a[i];
	int mn=sum;
	for(int i=n-1;i>=x;i--){
		sum=sum-(a[i+1]-a[i])*x+a[i]-a[i-x];
		mn=min(mn,sum);
	}
	return mn<=m;
}
signed main(){ IOS;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=l+(r-l)/2;
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

