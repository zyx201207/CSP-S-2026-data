#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],sum,i;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}if(m==n){
		sum=a[1];
		for(i=2;i<=n;i++){
			sum=sum&a[i];
			
		}
		cout<<sum;
		return 0;
	}
}
