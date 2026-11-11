#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N];
long long t[N];
bool sum(long long l,long long r){
	long long s=0;
//	cout<<l<<" "<<r<<"\n";
	for(long long i=r-1+1,j=r-l;i>l;j--,i--){
//		cout<<s<<"\n";
		s+=t[i]*j;
		if(s>m)return 0;
	}
	if(s<=m)return 1;
}
bool sum1(long long l,long long r){
	long long s=t[2]*(r-l+1)*(r-l)/2;
//	cout<<t[l]<<" "<<s<<"\n";
	if(s>m)return 0;
	else return 1;
}
bool check(long long x){
	if(n<=5000){
		for(long long i=x;i<=n;i++){
			if(sum(i-x+1,i))return 1;
		}
		return 0;
	}
	else {
		for(long long i=x;i<=n;i++){
			if(sum1(i-x+1,i))return 1;
		}
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		t[i]=a[i]-a[i-1];
//		cout<<t[i]<<" ";
	}
	long long left=1,right=n;
	while(left!=right){
//		cout<<left<<" "<<right<<"\n";
		long long mid=(left+right+1)/2;
		if(check(mid))left=mid;
		else right=mid-1;
	}
//	cout<<check(4)<<"\n";
	cout<<left;
	return 0;
}