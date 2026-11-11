#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],b[555555],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0;
	for(int i=2;i<=n;i++){
		if(i>1)b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(b[i]-b[mid]-(a[i]-a[mid])*(mid-1)<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}

