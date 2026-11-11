#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q[500005],mm;
long long l,r,ans=0,mid;
bool f=1;
long long max(long long a,long long b){
	if(a>b) return a;
	return b;
}
long long check(long long x){
	long long cnt=0,y=a[x];
	for(int i=1;i<=x;i++){
		if(a[i]<=y){
			cnt+=y-a[i];
		}
		if(cnt>m) break;
	}
	return cnt;
}
long long ck(long long l,long long r){
	long long cnt=0,y=a[r];
	for(int i=1;i<=r;i++){
		if(a[i]<=y){
			cnt+=y-a[i];
		}
		if(cnt>m) break;
	}
	return cnt;
}
int main(){
   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]-a[i-1]!=a[2]-a[1]&&i>2) f=0;
	}
	sort(a+1,a+n+1);
	if(f){
	
	l=1;r=n;
	while(l<=r){
		mid=l+(r-l)/2;
		mm=check(mid);
		if(mm>m){
			r=mid-1;
		}
		if(mm<=m){
			l=mid+1;
			ans=max(ans,mid);
		}

	}
	for(int i=ans+1;i<=ans+3&&i<=n;i++){
		if(check(i)<=m) ans=i;
	}
	cout<<ans;
	}
	else if(n<=5000){
		for(l=1,r=1;l<=n&&r<=n;){
			long long ansx=r-l+1;
			if(ck(l,r)<=m){
				r++;
				ans=max(ans,ansx);
				if(ans==n) break;
			}
			else l++;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
		q[i]=a[i]+q[i-1];
		}
		for(l=1,r=1;l<=n&&r<=n;){
			long long ansx=r-l+1;
			long long j=ansx*a[r]-(q[r-1]-q[l-1]);
			if(j<=m){
				r++;
				ans=max(ans,ansx);
				if(ans==n) break;
			}
			else l++;
		}
		cout<<ans;
	}
   return 0;
}
