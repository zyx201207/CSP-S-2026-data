#include<bits/stdc++.h>
#define N 500005
#define ll long long
#define ls(v) ((v)<<1)
#define rs(v) (((v)<<1)|1)
#define pa pair<int,int>
#define fi first
#define se second
using namespace std;
ll s[N],a[N],m;
int n,ans;
bool check(int l,int r){
	ll sl=a[r]*(r-l+1)-(s[r]-s[l-1]);
	return sl<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1,j=0;i<=n;i++){
		while(j<n&&check(i,j+1))j++;
		ans=max(ans,j-i+1);
	}cout<<ans;
	return 0;
}