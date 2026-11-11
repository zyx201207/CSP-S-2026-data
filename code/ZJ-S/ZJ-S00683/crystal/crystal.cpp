#include <bits/stdc++.h>
using namespace std;
long long n,m,e;
long long vis1=1,vis2=1;
long long a[500005];

bool check(long long sum){
	long long cc=(1+sum)/2*sum;
	return cc<=m;
}

bool checkk(long long summ){
	long long ccc=(1+summ)/2*summ;
	return ccc<=m/e;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			vis1=0;
		}
		if(i>=3){
			if((a[i]-a[i-1])!=(a[i-1]-a[i-2])){
				vis2=0;
			}
		}
	}
	
	if(n<=16){
		sort(a+1,a+1+n);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				long long sum=0;
				for(long long f=i;f<=j;f++){
					sum+=a[f];
				}
				long long h=j-i+1;
				if(((h*a[j])-sum)<=m){
					ans=max(ans,h);
				}
			}
		}
		cout<<ans;
		return 0;
	}else if(vis1==1){
		long long l=1,r=m;
		while(l<r){
			long long mid=(l+r+1)/2;
			if(check(mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<l+1;
		return 0;
	}else if(vis2==1){
		e=a[2]-a[1];
		long long q=a[1],w=a[n];
		while(q<w){
			long long midd=(q+w+1)/2;
			if(checkk(midd)){
				q=midd;
			}else{
				w=midd-1;
			}
		}
		cout<<q+1;
		return 0;
	}
	return 0;
}
