#include <bits/stdc++.h>
using namespace std;
long long n=1000000,a[1000000],m,b[1000000],ms,s,maxs;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]); 
	}
	int j=0;
	while(j<n){
		b[j]=a[j];
		if((b[j]-b[j-1])>(m/2)&&j>1){
			break;
		}
		j++;
	}
	if(j!=n){
		j-=0;
	}
	for(int z=j-1;z>=0;z--){
		long long ans=b[j-1];
		s=0;
		ms=0;
		for(int i=j-1;i>=0;i--){
			s++;
			ms+=ans-b[i];
			if(ms>=m)break;
		}
		if(s>maxs)maxs=s;
		j=j-1;
	}
	if(ms>m){
		maxs--;
	}printf("%lld",maxs);
	return 0;
}
