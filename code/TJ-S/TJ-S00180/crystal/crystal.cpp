#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int n,m,mx;
int a[N],s[N];
bool check(int l,int r){
	return s[r]-s[l-1]+m>=(r-l+1)*a[r];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++){
		int l=i,r=n,ans;
		while (l<=r){
			int mid=(l+r)/2;
			if (check(i,mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		mx=max(mx,ans-i+1);
	} 
	cout<<mx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
