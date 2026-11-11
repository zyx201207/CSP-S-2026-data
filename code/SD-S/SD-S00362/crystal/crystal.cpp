#include<cstdio>
#include<algorithm>
#define ll long long
const int MAXN=500005;
int max(int a,int b){
	return a>b?a:b;
}
int n,ans;
ll m,a[MAXN],s[MAXN];
bool is_fit(int l,int r){
	return a[r+1]*(r-l+1)-(s[r]-s[l-1])<=m;
}
int find(int i){
	int l=1,r=i-1,mid=(l+r)>>1;
	while(l<r){
		if(is_fit(mid,i-1)){
			r=mid;
		}
		else{
			l=mid+1;
		}
		mid=(l+r)>>1;
	}
	return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;++i){
		ans=max(ans,i-find(i)+1);
	}
	printf("%d",ans);
	return 0;
}
