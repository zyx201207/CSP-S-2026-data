#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l,r,mid,s;
long long check(int x){
	long long sum=LONG_LONG_MAX;
	for(int i=1;i<=n-x+1;i++){
		sum=min(sum,b[i+x-1]-b[i]-(a[i+x-1]-a[i])*(i-1));
	}
	return sum;
}
int main(){
	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
	}
//	cout<<a[4];
	l=1,r=n;
	while(1){
		mid=(r+l)/2;
		s=check(mid);
//		if(s==m) break;
		if(s>m){
			r=mid-1;
		}
		else l=mid+1;
		if(l>r) break;
	}
	s=check(mid);
	if(s>m) {
		while(1){
			mid--;
			s=check(mid);
			if(mid<=1||s<=m) break;
		}
	}
	else{
		while(1){
//			cout<<8;
			mid++;
			s=check(mid);
			if(mid>n||s>m) break;
		}
		mid--;
	}
//	cout<<check(mid)<<' '<<check(mid+1)<<endl;
	cout<<mid;
	return 0;
} 
