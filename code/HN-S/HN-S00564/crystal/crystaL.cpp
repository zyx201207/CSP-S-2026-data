#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],maxx;
bool check(long long x){
	long long sum=0;
	for(int i=1;i<x;i++){
		sum+=a[x];
	}
	return sum<=n;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	long long l=0,r=maxx,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
