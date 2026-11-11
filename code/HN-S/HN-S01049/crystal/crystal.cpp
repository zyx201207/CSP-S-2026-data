#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],s[N];
bool check(int mid){
	for (int i=mid;i<=n;i++) if (a[i]*mid-s[i]+s[i-mid]<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=0,r=n+1;
	while (l+1<r){
		int mid=(l+r)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%d",l);
	return 0;
} 
