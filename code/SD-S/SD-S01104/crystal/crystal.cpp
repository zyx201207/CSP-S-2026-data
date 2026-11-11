#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n],b[n-1];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n-1;i++){
		b[i]=a[i+1]-a[0];
	}
	do{
		m-=b[sum];
		sum++;
		}
	while(m>0);
	for(long long i=sum;i<n;i++){
		if(a[i-1]==a[i]) sum++;
	}
	cout<<sum;
	return 0;
}
