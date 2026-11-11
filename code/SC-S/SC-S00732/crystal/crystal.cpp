#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],sum[N];
ll get(int l,int r){
	return sum[r]-sum[l-1];
}
bool check(int l,int r){
	int len=r-l+1;
	ll flag=(a[r]*len)-get(l,r);//需要加多少 
	return flag<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	rep(i,1,n)
		cin >> a[i];
	sort(a+1,a+n+1);
	rep(i,1,n)
		sum[i]=a[i]+sum[i-1];
	ll ans=0;
	rep(i,1,n){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i))r=mid-1;
			else l=mid+1;
		}
		int pos=l;
		ll cur=(i-pos+1);
		ans=max(ans,cur);
	}
	cout << ans;
	
	return 0;
}