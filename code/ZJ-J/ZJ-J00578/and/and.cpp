#include<bits/stdc++.h>
using namespace std;

long long a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long mx=0;
	for(long long i=1;i<=n-m+1;i++){
		if(mx>i){
			break;
		}
		long long ans=1024*1024*1024-1;
		for(long long j=i;j<=i+m-1;j++){
			ans=ans&a[j];
		}
		mx=max(ans,mx);
	}
	cout<<mx;
	//¼ÇµÃ¸Älong long 
	return 0;
}
