#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=-1e18,minn=1e18,maxxx=-1,c1=1,c2=1;
long long a[500005];
bool check(long long v,long long y){
	long long x=upper_bound(a+1,a+n+1,v)-a,cnt=0;
	if(v!=a[x])x--;
	if(x<y)return 0;
	for(int i=x;i>=x-y+1;i--){
		cnt+=v-a[i];
	}
	if(cnt<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int d=0,lst=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst=a[i-1]-a[i-2];
		d=a[i]-a[i-1];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
		if(a[i]-a[i-1]!=1)c1=0;
		if(i>2&&lst!=d)c2=0;
	}
	sort(a+1,a+n+1);
	if(c1==1){
		long long l=1,r=n;
		while(l<r){
			long long mid=(l+r+1)>>1;
			if(mid*(mid+1)/2<=m)l=mid;
			else r=mid-1;
		}
		cout<<l+1;
		return 0;
	}if(c2==1){
		long long l=1,r=n;
		while(l<r){
			long long mid=(l+r+1)>>1;
			if(mid*(mid+1)/2*d<=m)l=mid;
			else r=mid-1;
		}
		cout<<l+1;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		int f=0;
		for(long long j=minn;j<=maxx;j++){
			if(check(j,i)){
				f=1;
				break;
			}
		}
		if(f)maxxx=max(maxxx,i);
		if(!f)break;
	}
	cout<<maxxx;
	return 0;
} 
