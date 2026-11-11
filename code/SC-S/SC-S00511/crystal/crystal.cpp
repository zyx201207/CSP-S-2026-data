#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[500010],b[500010],qz[500010],qz2[500010],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		qz[i]=qz[i-1]+b[i];
		qz2[i]=qz2[i-1]+qz[i];
	}
	n--;
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(qz2[mid]-qz2[i]<=m)l=mid+1;
			else r=mid;
		}
		int xb=upper_bound(qz2+1,qz2+n+1,qz2[mid])-qz2-1;
		ans=max(ans,xb-i+1);
	}cout<<ans;
}