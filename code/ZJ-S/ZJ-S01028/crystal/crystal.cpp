#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],ans;
bool chk(long long x){
	long long us=0;
	for(int i=1;i<x;i++)
		us+=a[x]-a[i];
	if(us<=m)
		return 1;
	for(int i=x+1;i<=n;i++){
		us-=a[i-1]-a[i-x];
		us+=(a[i]-a[i-1])*(x-1);
		if(us<=m)
			return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r){
		long long mid=l+r>>1;
		if(chk(mid)){
			ans=mid;
			l=mid+1;
		}else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
