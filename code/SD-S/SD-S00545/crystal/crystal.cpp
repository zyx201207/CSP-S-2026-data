#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e6+9;
int n;
ll m,a[N],sum[N];
bool check(int p){
	for(int i=1;i+p-1<=n;i++){
		if(a[i+p-1]*p-(sum[i+p-1]-sum[i-1])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid;
		}
	}
	for(int i=(min(n,ans+2));i>=max(1,ans-2);i--){
		if(check(i)){
			cout<<i;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}

