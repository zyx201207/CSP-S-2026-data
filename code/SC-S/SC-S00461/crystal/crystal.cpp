#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N];
bool _check(int x){
	int sum=0;
	for(int i=1;i<x;i++)
	    sum+=a[x]-a[i];
    if(sum<=m) return true;
    else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(_check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}