#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sum1=0;
	int m,n,a[250005],b[250005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} for(int i=1;i<=n;i++){
		long long minn=100000;
		int sum;
	 	for(int j=1;j<=n;j++){
	 		if(a[j]<minn) {
	 			minn=a[j];
	 			sum=j;
			 }
		}b[i]=minn;
		a[sum]=100000;
	 } for(int i=1;i<=n;i++){
		int cnt=0;
	 	for(int j=1;j<=i;j++){
	 		cnt+=b[i]-b[j];
		}
		a[i]=cnt;
	} for(int i=1;i<=n;i++){
		if(m>=a[i]){
			sum1=i;
		} else break;
	} cout<<sum1;
	return 0;
} 
