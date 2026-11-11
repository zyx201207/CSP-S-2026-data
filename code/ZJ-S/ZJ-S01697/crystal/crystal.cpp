#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50001],b[50001],c[50001],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		c[i]=a[i]*i;
	}
	int i=1;
	while(abs(c[i]-b[i])<=m&&i<=n){
		i++;
		sum++;
	}
	cout<<sum;
	return 0;
}