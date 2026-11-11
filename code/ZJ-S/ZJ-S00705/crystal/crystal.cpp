#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],x=1,y;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	y=n;
	while(x<=y){
		long long mid=x+y>>1,num=a[mid],d=0;
		d+=sum[y]-sum[mid]-num*(y-mid);
		d+=num*(mid-x)-sum[mid-1]+sum[x-1];
		if(d<=m){
			cout<<y-x+1;
			return 0;
		}
		if(a[y]-num>=num-a[x])--y;
		else ++x;
	}
	cout<<1;
	return 0;
}
//mima:Oct31==Dec25?
