#include<bits/stdc++.h>
#define llo long long 
using namespace std;
const int N=5e5+10;
llo a[N],m,c[N],su1[N],su2[N];
int ans=1;
int n;
int check(int x){
	int l=0,r=x,mid;
	while(l+1!=r){
		mid=l+r>>1;
		if(m>=su2[mid]-su2[x]-su1[x]*(x-mid))r=mid;
		else l=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int i=n-1;i>=0;i--){
		su1[i]=su1[i+1]+c[i];
	}
	for(int i=n-1;i>=0;i--){
		su2[i]=su2[i+1]+su1[i];
	}
	for(int i=2;i<=n;i++){
		int k=check(i);
		ans=max(ans,i-k);
	}
	printf("%d",ans);
	return 0;
} 