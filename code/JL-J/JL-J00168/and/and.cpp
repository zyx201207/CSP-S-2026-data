#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000){
		if(m==n-1){
			int mind=a[1];
			for(int i=2;i<=n;i++){
				if(a[i]<mind){
					mind=a[i];
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==mind){
					int t=a[i];
					a[i]=a[1];
					a[1]=t;
					break;
				}
			}
			sum=a[n];
			for(int i=n;i>=2;i++){
				sum=sum&a[i];
			}
			cout<<sum;
		}else{
			sum=a[n];
			for(int i=n;i>=m;i++){
				sum=sum&a[i];
			}
			cout<<sum;
		}
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n/2;i++){
			long long t=a[i];
			a[i]=a[n-i+1];
			a[n-i+1]=t;
		}
		sum=a[1];
		for(int i=1;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	return 0;
}
