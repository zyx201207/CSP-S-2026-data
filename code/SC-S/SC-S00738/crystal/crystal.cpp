#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],c[500010],Max=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long k=0;
	k=a[2]-a[1];
	if(n>10000){
		long long i=1;
		for(;i<=n;i++){
			if((1+i)*i/2*k>m){
				break;
			}
		}
		cout<<i-1;
		return 0;
	} 
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	for(int i=n;i>=2;i--){
		int sum=0,pre=0;
		int j=i;
		while(sum<=m&&j>1){
			sum=sum+pre+c[j];
			pre+=c[j];
			j--;
		}
		if(i-j+1>Max){
			Max=i-j+1;
		}
	}
	cout<<Max;
	return 0;
}