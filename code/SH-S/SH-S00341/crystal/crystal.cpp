#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n;
long long m,a[N];

bool check(int x){
	long long sum=0;
	for(int i=1;i<=x;++i)
		sum+=a[x]-a[i];
	if(sum<=m) return true;
	for(int r=x+1;r<=n;++r){
		sum-=a[r-1]-a[r-x];
		sum+=(x-1)*(a[r]-a[r-1]);
		if(sum<=m) return true;
	}
	return false;
}

int work(){
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	return l;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	printf("%d",work());
	return 0;
}
