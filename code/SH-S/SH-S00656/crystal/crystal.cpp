#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,f;
long long a[500005],d[500005]; 
bool check(int x){
	long long sum=INT_MAX;
	for(int i=2;i<=n-x+2;i++){
		long long sm=0;
		int c=1;
		for(int j=i;j<=i+x-2;j++){
			sm+=d[j]*c;
			c++;
			if(sm>m){
				break;
			}
		}
		sum=min(sum,sm);
	}
	if(sum<=m){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
