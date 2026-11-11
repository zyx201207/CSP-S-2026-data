#include<bits/stdc++.h>
using namespace std;
const int maxn=6e5+1;
long long n,m,a[maxn],b[maxn];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)b[i]=b[i-1]+b[i]*(i-1);
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(b[mid]<=m+b[i])l=mid+1;
			else r=mid;
		}
		ans=max(ans,r-i);
	}
	cout<<ans;
	return 0;
}
//怎么想感觉都是数据的锅 
