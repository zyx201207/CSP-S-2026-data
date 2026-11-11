#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long m,n,a[500005],b[500005],sum,ans;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=abs(a[i+1]-a[i]);
	}
	sum=b[1];int x=0;
	for(long long i=2;i<n;i++){
		sum+=b[i]*2;
		if(sum>m) {
			ans=max(i-x,ans);
			sum=b[i];
			x=i-1;
		}
	}
	cout<<a[8]+a[28];
	return 0;
} 
