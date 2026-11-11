#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const ll MAXN=1e18;
int n;
ll a[N],b[N],m;
bool check(int p){
	ll res=MAXN;
	for(int i=1;i+p-1<=n;i++){
		ll s=a[i+p-1];
		ll num=p*s-(b[i+p-1]-b[i-1]);
		res=min(num,res);
	}
	return res<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
} 