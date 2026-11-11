#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
const ll inf = 1e18;
ll n,m,ans,a[N],dif[N],suma[N],suf[N],sumsuf[N];
ll getdif(int l,int r,ll len){
	return sumsuf[r]-sumsuf[l-1]-suf[r]*len;
}
bool check(int mid){
	ll cnt=inf;
	for(int i=mid;i<=n;i++)
		cnt=min(cnt,getdif(i-mid+1,i,mid));
	return cnt<=m?1:0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		suma[i]=suma[i-1]+a[i];
	for(int i=2;i<=n;i++)
		dif[i]=a[i]-a[i-1];
	for(int i=n-1;i>=1;i--)
		suf[i]=suf[i+1]+dif[i+1];
	for(int i=1;i<=n;i++)
		sumsuf[i]=sumsuf[i-1]+suf[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}