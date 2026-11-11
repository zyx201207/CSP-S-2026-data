#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen(crystal.in;"r";stdin);
	freopen(crystal.out;"m";stdout);
	int n,i,j,b=0,z,c=0;
	long long m;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=n-1;i>=0;i--){
		z=a[i]*(i+1);
		for(j=i-1;j<=0;j--){
			if(a[j]<0)
			{
				b=b+(-1*a[j]-a[i]);
			}
			else{
				b=b+a[i]-a[j];
			}
			c++;
			if(b==m){
				cout<<c;
			}
		}
		c=0;
		b=0;
	}
	
	return 0;
}