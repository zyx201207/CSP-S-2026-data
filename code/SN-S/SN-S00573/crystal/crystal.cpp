#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long num[n+5],cha[n+5],chaall=0;
	long long max1=-1000000000000,max2;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]>=max1){
			max2=i;
			max1=num[i];
		}
	}
	for(int i=1;i<=n;i++){
		cha[i]=max1-num[i];
		chaall+=cha[i];
	}
	int numall=n;
	while(chaall>m){
		long long max=max1;
		
		num[max2]=-1000000000000;
		max1=-1000000000000;
		for(int j=1;j<=n;j++){
			if(num[j]>=max1){
				max2=j;
				max1=num[j];
			}
		}
		chaall-=(max-num[max2])*numall;
		numall--;
	}
	cout<<numall;
	return 0;
}
