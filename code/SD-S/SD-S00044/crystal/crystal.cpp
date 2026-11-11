#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[510005],b[510005],t,tt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long j=1,i=1;
	for(;i<=n;){
		for(;;){
			if(a[j+1]*(j+1-i+1)-(b[j+1]-b[i-1])<=m&&j<n){
			    
				j++;
			}
			else{
				break;
			}
		} 
		tt=max(tt,j-i+1);
		//cout<<i<<" "<<j<<"\n";
		//t=t-(a[i+1]-a[i])*(j-i);
		i++;
	}
	cout<<tt;
} 
