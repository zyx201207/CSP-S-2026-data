#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		int cnt=0;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(pre[i-1]-pre[mid-1])<=m){
				r=mid;
				cnt=mid;
			}else l=mid+1;
			if(l==r&&(i-l)*a[i]-(pre[i-1]-pre[l-1])<=m)cnt=mid;
		}
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/