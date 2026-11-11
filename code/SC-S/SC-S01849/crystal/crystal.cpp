#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,cnt0,c[500005];
bool cmp(long long x,long long y){
	return x<y;
}
bool ch(int x){
	long long cntt=0;
	for(int i=2;i<=x;i++) cntt+=c[i]*(i-1);
	if(cntt<m) return 1;
	for(int i=x;i<n;i++){
		cntt-=(a[i]-a[i-x+1]);
		cntt+=c[i+1]*(x-1);
		if(cntt<m) return 1; 
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(ch(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}