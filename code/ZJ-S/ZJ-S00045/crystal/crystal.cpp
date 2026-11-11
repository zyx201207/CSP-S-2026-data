#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll INF=1e18;
ll a[N];
ll pre[N];
ll sum[N];
ll n,m;
bool check(int x){
	ll mn=INF;
	for(int i=1;i<=n-x-2;i++){
		mn=min(mn,sum[i+x-2]-sum[i-1]);
	}
	if(mn<=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);//!!!
	freopen("crystal.out","w",stdout);//!!!
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]+(a[i+1]-a[i]);
	}
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+pre[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<l+1;
	return 0;
}