#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,mx;
long long a[N],s[N],m;
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n+1,mid;
		while(l<r-1){
			mid=(l+r)>>1;
			if((mid-i)*a[mid]-s[mid-1]+s[i-1]<=m)l=mid;
			else r=mid;
		}
		mx=max(mx,l-i+1);
	}
	printf("%d\n",mx);
}