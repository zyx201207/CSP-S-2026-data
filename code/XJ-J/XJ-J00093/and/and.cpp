#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],sum,maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==n-1){
		sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
		}
		for(int i=1;i<=n;i++){
			long long p=sum&a[i];
			maxx=max(maxx,p);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long p=a[i]&a[j];
				maxx=max(maxx,p);
			}
		}
		cout<<maxx;
		return 0; 
	}
	return 0;
} 
