#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int st[500005];
bool check(int x){
	int minv=1000000000000000005;
	for(int i=1;i<=n-x+1;i++){
		int j=i+x-1;
		int tv=a[j]*(x-1)-(st[j-1]-st[i-1]);
		minv=min(tv,minv);
	}
	return minv<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		st[i]=st[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}