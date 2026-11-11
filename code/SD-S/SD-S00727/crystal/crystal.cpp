#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],ans=0,m;
long long bound(int l,int r){
	long long x=l,y=r;
	long long mid=(x+y)/2;
	while(x+1<y){	
		mid=(x+y)/2;
		if((mid-l+1)*a[mid]-sum[mid-1]+sum[l-2]>m){
			y=mid-1;
		}
		else if((mid-l+1)*a[mid]-sum[mid-1]+sum[l-2]==m){
			return mid;
		}
		else{
			x=mid+1;
		}
	}
	if((mid-l+1)*a[mid]-sum[mid-1]+sum[l-2]>m){
		return mid-1;
	}
	while((mid-l+1)*a[mid]-sum[mid-1]+sum[l-2]>m){
		mid++;
	}
	if((mid-l+1)*a[mid]-sum[mid-1]+sum[l-2]>m){
		return mid-1;
	}
	return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<n;i++){
		ans=max(ans,bound(i+1,n)-i+1);
	}
	cout<<ans;
	return 0;
}

