#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	int ans=1,tot=1,l=1;
	for(int i=2;i<=n;++i){
		while((a[i]-a[i-1])*tot>m&&l<i){
			m=m+a[i-1]-a[l];
			l++,tot--;
		}
		m=m-(a[i]-a[i-1])*tot;
		tot++;
		ans=max(ans,tot);
	}
	printf("%lld",ans);
	return 0;
} 
