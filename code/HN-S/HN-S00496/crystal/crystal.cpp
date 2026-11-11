#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],p[500005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		int sum=0;
		for(int j=1;j<=mid;j++){
			sum+=a[mid]-a[j];
		}
		if(sum<=m){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
