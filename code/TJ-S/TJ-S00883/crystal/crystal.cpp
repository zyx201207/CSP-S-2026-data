#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
long long sum[N];
bool check(long long mid){
	for(int i=1;i<=n-mid+1;i++){
		long long cha=sum[i+mid-1]-(sum[i]*(i));
		//if(mid==4) cout<<cha;
		if(cha<=m) return 1;
	}
	return 0;
}
bool check1(long long mid){
	
	for(int i=1;i<=n-mid+1;i++){
		long long cha=0;
		for(int k=i;k<i+mid-1;k++){
			cha+=(a[i+mid-1]-a[k]);
		}
		//cout<<m;
		//cout<<cha;
		//if(mid==4) cout<<cha;
		//if(mid==5) cout<<cha;
		if(cha>m){
			//cout<<1;
			//cout<<mid;
			continue;
		}
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long maxx=0;//minn=2e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		//minn=min(minn,a[i]);
	}
	//cout<<m;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1]+sum[i-1];
		//cout<<sum[i]<<' ';
		//sum[i]+=sum[i-1];
	}
	for(int i=2;i<=n;i++) sum[i]+=sum[i-1];
	//for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
	long long l=1,r=n;
	long long ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(n<=5000){
			bool is=check1(mid);
			//cout<<is;
			if(is){
				
				ans=mid;
				//cout<<ans;
				l=mid+1;
				
			}else r=mid-1;
			continue;
		}else{
			if(check(mid)){
				//cout<<2;
				l=mid+1;
				ans=mid;
			}else r=mid-1;
		}
		
	}
	cout<<ans;//xym
	return 0;
}
