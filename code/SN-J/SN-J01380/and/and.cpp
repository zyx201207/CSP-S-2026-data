#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],sum,ans=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			sum=a[i];
			for(int j=i+1;j<=n;j++){
				sum=sum&a[j];
				ans=max(ans,sum);
				sum=a[i];
			}
		}
		cout<<ans;
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	return 0;
} 


