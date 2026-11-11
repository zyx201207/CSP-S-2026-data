#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans;
int res[N];
int ll;
bool check(int l,int r){
	int sum=res[r]-res[l-1];
	int cnt=a[r]*(r-l+1)-sum;
	if(cnt<=m)return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)res[i]=res[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int t=__lg(m);
		int r=i;
		for(;t>=0;t--)
			if(r+(1<<t)<=n&&check(i,r+(1<<t)))r+=(1<<t);
		ans=max(r-i+1,ans);
	}
	printf("%lld\n",ans);
	return 0;
}