#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
int n;
ll m,a[N],sf[N],SF;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		SF+=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)sf[i]=sf[i+1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(1ll*(i-mid)*a[i]-(sf[mid]-SF)<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
		SF-=a[i];
	}
	printf("%d",ans);
	return 0;
}