#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxx=-1,sum=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]);
		
	}
	for(int i=m;i>=1;i--){
		sum=a[m];
		a[m]=a[m]&a[m-1];
	}
	if(m==1){
		cout<<maxx;
		return 0;  
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	return 0;
}
