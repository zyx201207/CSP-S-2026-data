#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N];
int ans;
int check(int l,int r){
	return (r-l+1)*a[r]-pre[r]+pre[l-1];
}
int search(int s){
	int l=s,r=n,ans=s;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(s,mid)<=m){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,search(i)-i+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
