#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		a[i]=a[i+1]-a[i];
	}
	a[n]=0;
	for(long long i=n;i>=1;i--){
		a[i]=a[i]+a[i+1];
	}
	long long mx=0,ans=0;
	for(long long i=n,j=n-1;i>=1&&j<=i&&j>=1;){
		if(ans<=m){
			mx=max(mx,i-j+1);
			ans+=a[j-1]-a[i];
			j--;
		}else{
			ans-=(i-j)*(a[i-1]-a[i]);
			i--;
		} 
	}
	cout<<mx;
	return 0;
}
