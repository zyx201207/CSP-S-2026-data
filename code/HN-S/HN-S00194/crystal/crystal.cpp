#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],sum[N];
bool boo(long long x){
	for(int i=1;i<=n;i++){
		long long pp=i+x-1;
		if(pp>n){
			break;
	 	}
		long long lyl=sum[pp]-sum[i]-(a[pp]-a[i])*(i-1);
		if(lyl<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int A=1,B=2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			A++;
		}
	}
	sort(a+1,a+1+n);
	long long t=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]==a[i+1]-t){
			B++;
		}
	}
	if(A==n){
		cout<<n;
		return 0;
	}
	if(B==n){
		long long B1=0,B2=1;
		for(int i=1;i<=n-1;i++){
			if(B1+i*t<=m){
				B2++;
				B1+=i*t;
			}
			else break;
		}
		cout<<B2;
		return 0;
	}
	sum[1]=0;
	for(int i=2;i<=n;i++){
		sum[i]=(a[i]-a[i-1])*(i-1)+sum[i-1];
	} 
	long long l=1,r=n,ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(boo(mid)){
			ans=mid;
			l=mid+1;
		} 
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
