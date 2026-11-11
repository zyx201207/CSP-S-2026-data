#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],fh[N],ans;
bool check(int mid){
	long long cnt=fh[mid];
	for(int i=mid,j=1;i<=n;i++,j++){
		if(i>mid) cnt+=mid*(a[i]-a[i-1])-(a[i]-a[j-1]);
		if(cnt<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) fh[i]=fh[i-1]+1LL*(i-1)*(a[i]-a[i-1]);
	int l=1,r=n;
	while(r>=l){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
