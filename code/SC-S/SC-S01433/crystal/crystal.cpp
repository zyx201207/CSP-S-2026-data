#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],mx=-1e16,k=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			k=1;
		}
	}
	if(k==0){
		long long sum=0,l=0;
		for(long long i=1;i<=n;i++){
			if(sum+i*(a[2]-a[1])>m){
				cout<<i;
				l=1;
				break;
			}
			sum+=i*(a[2]-a[1]);
		}
		if(l==0)cout<<n;
	}else {
		for(int i=1;i<=n;i++){
			b[i]=a[n]-a[i];
		}
		for(long long i=1;i<=n;i++){
			long long sum=0;
			bool l=0;
			for(long long j=i-1;j>0;j--){
				if(sum+b[j]-b[i]>m){
					mx=max(mx,i-j);
					l=1;
					break;
				}
				sum+=b[j]-b[i];
			}
			if(l==0)mx=max(mx,i);
		}
		cout<<mx;
	}
	return 0;
}