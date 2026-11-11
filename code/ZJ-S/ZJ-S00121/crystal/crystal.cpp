#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool check(long long x){
	long long cost=0;
	for(int i=1;i<=x;i++){
		cost+=a[x]-a[i];
	}
	for(int i=x;i<=n;i++){
		if(i!=x){			
			cost-=(a[i-1]-a[i-x]);
			cost+=(a[i]-a[i-1])*(x-1);
		}
		if(cost<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,ans=l;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
}
