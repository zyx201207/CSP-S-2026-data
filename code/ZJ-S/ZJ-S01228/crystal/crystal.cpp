#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[510000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	bool f=false,t=false;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i){
			f=true;
		}
		if(i>=3&&a[i]-a[i-1]!=a[2]-a[1]){
			t=true;
		}
	}
	if(f==false){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=ans+i;
			if(ans==m){
				printf("%d",i+1);
				return 0;
			}
			else{
				if(ans>m){
					printf("%d",i);
					return 0;
				}
			}
		}
		return 0;
	}
	if(t==false){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=ans+i*abs(a[2]-a[1]);
			if(ans==m){
				printf("%d",i+1);
				return 0;
			}
			else{
				if(ans>m){
					printf("%d",i);
					return 0;
				}
			}
		}
		return 0;		
	}
	
	return 0;
} 
