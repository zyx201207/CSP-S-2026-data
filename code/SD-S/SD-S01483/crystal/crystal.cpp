#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long m,n,a[500005],b[500005],sum,ans;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f=0;
	}
	long long k=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=k){
			f=0;
		}
	}
	if(k==1&&f!=0){
		f=1;
	}
	else if(k!=1&&f!=0) f=2;
	
	sort(a+1,a+n+1);
	if(m>n*(a[n]-a[1])) {
		cout<<n;	
		return 0;
	}
	if(f==1) {
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum=(1+i)*i/2;
			if(sum==m) cout<<i;
			if(sum>m) cout<<i-1;
		}
	}
	else if(f==2){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum=(a[1]+i)*i/2;
			if(sum==m) cout<<i;
			if(sum>m) cout<<i-1;
		}
	}
	else{
		long long ans=0;
		for(int j=1;j<=n;j++){
			long long x=a[j],sum=0,cnt=0;
			for(int i=1;i<=j+1;i++){
				
					sum+=abs(x-a[i]);
					if(sum>m){
						ans=max(ans,cnt);
						cnt=0;
						sum=abs(x-a[i]);
					}
					else{
						cnt++;
					}
				
			}
			
		}
		cout<<ans;
	}
	
	return 0;
} 
