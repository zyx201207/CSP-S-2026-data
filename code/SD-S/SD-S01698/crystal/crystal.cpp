#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum,s=0;
	long long a[n*2];
	scanf("%lld",&n);
	scanf("%lld",&m);
		for(int i=0;i<n;i++){
		scanf("%lld",a[i]);
		if(a[i]>=a[i+1]){sum=a[i]-a[i+1];}
		else{sum=a[i+1]-a[i];}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			if(a[j]>=a[j+1]){
				if(a[j]-a[j+1]<=sum){
					sum=a[j]-a[j+1];
					if(sum==1){
						a[j+1]+=1;
					}
				}
			}
			else{
				if(a[j+1]-a[j]<=sum){
					sum=a[j+1]-a[j];
					if(sum==1){
						a[j]+=1;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				s+=1;
			}
		}
	}
	printf("%lld",s);
	
	return 0;
}

