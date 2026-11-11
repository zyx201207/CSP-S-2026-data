#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long n,m;
long long a[N],tot[N];
bool check(long long len){
	for(int l=1;(l+len-1)<=n;l++){
		int r=(l+len-1);
		long long tag=a[r]*len-(tot[r]-tot[l-1]);
		if(tag<=m) return true;
	}
	return false;
}
long long find_ans(long long l,long long r){
	if(l==r) return l;
	long long mid=(l+r+1)/2;
	if(check(mid)) return find_ans(mid,r);
	else return find_ans(l,mid-1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) tot[i]=tot[i-1]+a[i];
	printf("%lld\n",find_ans(1,n));
	return 0;
}