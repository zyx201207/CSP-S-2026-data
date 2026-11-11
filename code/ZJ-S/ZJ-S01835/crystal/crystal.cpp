#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long n,m,a[MAXN],s[MAXN],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long l=i,r=n,mid;
		while(l<r){
			mid=((l+r)>>1);
			long long now=a[mid]*(mid-i+1)-s[mid]+s[i-1];
			if(now>m)r=mid;
			else if(now<=m&&a[mid+1]*(mid-i+2)-s[mid+1]+s[i-1]>m){
				l=mid;
				break;
			}
			else l=mid+1;
		}
		ans=max(ans,l-i+1);
	}
	printf("%lld\n",ans);
	return 0;
}