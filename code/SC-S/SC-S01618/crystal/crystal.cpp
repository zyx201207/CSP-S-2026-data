#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int n;
ll m,a[N],sum[N];
int query(int d){
	int l=1,r=d;
	while(l<r){
		int mid=(l+r)/2;
		ll val=a[d]*(d-mid+1)-(sum[d]-sum[mid-1]);
		if(val<=m)r=mid;
		else l=mid+1;
	}
	return r;
}
int main(){
//	freopen("C:\\Users\\user\\Desktop\\输入.txt","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,i-query(i)+1);
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}