#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],c[N],sum[N];
bool check(int len){
	int flag=0,f=0,cnt=0;
	ll s=0;
	for(int i=len;i>=2;i--){
		s+=c[i]*(i-1);
	}
	if(s<=m) flag=1;
	for(int i=len+1;i<=n;i++){
		s=s-sum[i-1]+sum[i-len]+(len-1)*c[i];
		if(s<=m) flag=1;
	}
	return flag;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+c[i];
	}
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
//Accepted at 15:14
