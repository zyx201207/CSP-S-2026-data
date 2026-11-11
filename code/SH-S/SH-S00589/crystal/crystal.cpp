#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],c[500001];
int ans;
bool cmp(int x,int y){
	return x<y;
}
long long f(int x,int y){
	long long sum=0;
	/*for(i=y-1;i>=x;i--){
		sum+=a[y]-a[i];
	}*/
	sum=b[y]-b[x];
	sum-=(c[y]-c[x])*(x-1);
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		c[i]=a[i]-a[i-1]+c[i-1];
	}
	int l=1,r=1;
	while(r<=n){
		long long c=f(l,r);
		if(c<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}
