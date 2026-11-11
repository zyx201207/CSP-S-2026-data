#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+5;
int n,ans;
LL m,cnt,a[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	for(int l=0,r=1;r<n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		if(cnt>m)while(l<=r&&cnt>m)cnt-=(a[r]-a[l]),l++;
		ans=max(r-l+1,ans);
	}printf("%d\n",ans);
	return 0;
}
