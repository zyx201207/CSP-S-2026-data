#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1,x;i<=n;i++){
		x=m;
		for(long long j=i+1;j<=n;j++){
			x=x-(a[j]-a[j-1])*(j-i);
			if(x<0)break;
			maxn=max(maxn,j-i+1);
		}
	}
	cout<<maxn;
	return 0;
}
