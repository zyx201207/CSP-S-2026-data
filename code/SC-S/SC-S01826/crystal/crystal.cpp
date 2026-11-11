#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[501010];
long long qian[501010];
bool check(int i,int mid){
	long long he=qian[i]-qian[mid]-(mid-1)*(a[i]-a[mid]);
	if(he<=m){
		return 1;
	}else{
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
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qian[i]=qian[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int mid=l+(r-l)/2;
		while(l<=r){
			mid=l+(r-l)/2;
			if(check(i,mid)){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}