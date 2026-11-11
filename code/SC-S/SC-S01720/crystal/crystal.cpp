#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=5e5+7;
//typedef long long ll;
#define int long long
int n,m,a[maxn],inv[maxn],l,r;
inline int get_power(int x,int y){return(1ll*a[x]*(y-1)-inv[x-1]+inv[x-y]);}
int solve(int num){
	int ret=0x7fffffff;
	for(int i=num;i<=n;++i)
		ret=min(ret,get_power(i,num));
	return(ret);
}signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		inv[i]=inv[i-1]+a[i];
	for(l=1,r=n;l<=r;){
		const int mid=(l+r)>>1,ret=solve(mid);
		if(ret<=m)l=mid+1;
		else r=mid-1;
	}cout<<r<<'\n';
	return(0);
} 