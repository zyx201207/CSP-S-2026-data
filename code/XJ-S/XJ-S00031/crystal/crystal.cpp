#include<bits/stdc++.h>
using namespace std;
int n,a[500001];
long long p[500001],sum,ans,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	p[1]=0;
	for(int i=2;i<=n;i++)p[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)p[i]=p[i-1]+p[i]*(i-1);
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			sum=p[mid]-p[i];
			if(sum>m){
				r=mid-1;
			}else if(sum<=m){
				l=mid+1;
			}
		}
		ans=max(ans,l-i);
	}
	cout<<ans;
	return 0;
}
