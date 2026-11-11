#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	cin>>n;
	if(n>=5001){
   		long long m;
		cin>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long d;
		d=a[n]-a[n-1];
		long long k=0;
		long long ans=1;
		while(m>=k){
			k=ans*(ans+1)*d/2;
			ans++;
		}
		cout<<ans-1;
	}
	else{
		long long m;
		int ans=1;
		cin>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+0,a+n+1);
		for(int i=1;i<=n;i++){
			if(i!=n){
				b[i]=a[i+1]-a[i];
			}
		}
		long long shuju;
		shuju=m;
		int k=0;
		int ansa=1;
		for(int i=1;i<=n;i++){
			shuju=m;
			while(shuju>=0 && k==0){
				shuju-=ansa*(b[i+ansa-1]);
				if(ansa+i-1==n){
					k=1;
				}
				ansa++;
			}
			if(ansa-1>=ans){
				ans=ansa-1;
			}
			ansa=1;
		}
		cout<<ans;
	}
	return 0;
}        
