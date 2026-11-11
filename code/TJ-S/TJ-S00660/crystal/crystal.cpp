#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[500009];
long long b[500006];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	unsigned long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	
	for(int i=1;i<n;i++){
		b[i]*=i; 
		
	}
	unsigned long long sum=0,ans=0;
	for(int i=1;i<n;i++){
		if(sum+b[i]>m){
			ans+=i;break;
		}sum+=b[i];
	}
	cout<<ans;
	return 0;
} 



