#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],d[500005];
int ans=1;
int work(int p){
	int l=1,r=p;
	while(l<r){
		int mid=(l+r)/2;
		long long tmp=d[p]-d[mid]-(a[p]-a[mid])*(mid-1);
		if(tmp>m){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return p-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+(b[i]*(i-1));
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,work(i));
	}
	cout<<ans;
	return 0;
}
