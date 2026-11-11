#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum,maxx,a[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		k=a[1];
		for(int i=1;i<=n;i++){
			k=k&a[i];
		}
		cout<<k;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				k=max(k,a[i]&a[j]);
			}
		}
		cout<<k;
		return 0;
		
	}
	if(m==n-1){
		k=a[1];
		for(int i=1;i<=n;i++){
			k=k&a[i];
		}
		long long p;
		for(int i=1;i<=n;i++){
			p=k;
			p=p&a[i];
			sum=max(sum,p);
		}
		cout<<sum;
		return 0;
	}
	return 0;
} 
