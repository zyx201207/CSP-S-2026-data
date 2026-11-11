#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005]={0},minn=LLONG_MAX,maxn=LLONG_MIN,ans=0;
void solv(){
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(a[j]*(j-i+1)-(sum[j]-sum[i-1])<=m){
				if(j-i+1>ans) ans=j-i+1;
			}
		}
	}
	return;
}
void ssolve(long long pluss){
	long long s=0;
	for(long long i=1;i<=n;i++){
		s+=i*pluss;
		if(s>m){
			ans=i;
			return;
		}
	}
	ans=n;
	return;
}
long long check(int x){
	long long sum=0,s=m;
	bool flag=false;
	for(long long i=n;i>=1;i--){
		if(a[i]<=x){
			if(s>=x-a[i]) sum++,s=s-(x-a[i]);
			else flag=false;
		}
	}
	if(ans<sum) ans=sum,flag=true;
	return flag;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn) minn=a[i];
		if(a[i]>maxn) maxn=a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		solv();
		cout<<ans;
		return 0;
	}else{
		bool fflag=true;
		long long pluss=a[2]-a[1];
		if(pluss==0){
			cout<<n;
			return 0;
		}
		for(long long i=3;i<=n;i++) if(a[i]-a[i-1]!=pluss) fflag=false;
		if(fflag==true){
			ssolve(pluss);
			cout<<ans;
			return 0;
		}
	}
	long long l=minn,r=maxn;
	while(l<r){
		long long mid=(l+r)/2;
		if(check(mid)==true) l=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}