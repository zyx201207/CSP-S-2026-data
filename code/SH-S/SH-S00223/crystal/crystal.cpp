#include<cstdio>
#include<cstdlib>
#include<algorithm>
int n,ans;
long long m,a[500005],s[500005];
bool A=1,B=1;
void propertyA(){
	if(m*2>=(long long)n*(n-1)){
		printf("%d",n);
		return;
	}
	int l=1,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(m*2>=(long long)mid*(mid-1))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d",r);
}
void propertyB(){
	if(m*2>=(long long)n*(n-1)*(a[1]-a[0])){
		printf("%d",n);
		return;
	}
	int l=1,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(m*2>=(long long)mid*(mid-1)*(a[1]-a[0]))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d",r);
}
int find(int i){
	if(i*a[i]-s[i-1]<=m)
		return i+1;
	int l=1,r=i;
	while(l<=r){
		int mid=(l+r>>1);
		if((i-mid)*a[i]+s[mid-1]-s[i-1]<=m)
			r=mid-1;
		else
			l=mid+1;
	}
	return i-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%lld",&a[i]);
	std::sort(a,a+n);
	for(int i=0;i<n;++i)
		if(a[i]!=i+1)
			A=0;
	if(A){
		propertyA();
		return 0;
	}
	for(int i=2;i<n;++i)
		if(a[i]-a[i-1]!=a[1]-a[0]){
			B=0;
			continue;
		}
	if(B){
		propertyB();
		return 0;
	}
	s[0]=a[0];
	for(int i=1;i<n;++i)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<n;++i){
		int k=find(i);
		if(k>ans)
			ans=k;
	}
	printf("%d",ans);
	return 0;
}
