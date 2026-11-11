#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,ans,a[500005];
ull m;
bool check(int x){
	ull last=0,summ=1e13;
	for(int i=1;i<=x;i++) last+=a[x]-a[i];
	summ=min(summ,last);
	for(int i=2;i<=n-x+1;i++)
		last=last-(a[i+x-2]-a[i-1])+(x-1)*(a[i+x-1]-a[i+x-2]),summ=min(summ,last);
	if(summ<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
