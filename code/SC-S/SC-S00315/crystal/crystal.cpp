#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+3;
ll m,a[maxn],pre[maxn];
int n,l,r,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=i,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if((mid-i+1)*a[mid]-(pre[mid]-pre[i-1])<=m)l=mid;
			else r=mid-1;
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}