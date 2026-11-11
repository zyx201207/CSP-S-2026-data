#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+34,INF=0X3f3f3f3f;
ll n,m;
ll a[N];
ll sum[N];

bool check(int mid){
	for(int i=mid;i<=n;i++){
		int r=i,l=i-mid+1;
		if( (mid-1)*a[r]-(sum[r-1]-sum[l-1]) <= m)return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
