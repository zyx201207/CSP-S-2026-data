//刘启安 SN-S00332 西北大学附属中学 
#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5000001],ax=0;
long long zx(int y,int z){
	int i=y+1;
	while(x[i]-x[y]<=d){
		if(i==z){
			return 1;
		}i++;
	}
	return 1+zx(y+i-1,z);
}	
long long sj(int y,int z){
	long long mi=zx(y,z),flf=0;
	int i=y;
	while(i<=z){
		if(1+(zx(i,y))==mi){
			flf++;
		}i++;
	}
	if(flf==2){
		return 1;
	}else{
		return 0;
	}
}
long long nu(int y){
	for(int i=y;i<n;i++){
		if(i==y){
			return ax+nu(y+1); 
		}else{
			return sj(y,i)+nu(y+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	scanf("%ld%ld",&c,&t);
	for(long long q=0;q<t;q++){
		scanf("%ld%ld",&n,&d);
		for(int i=0;i<c;i++){
			scanf("%ld",x[i]);
		}
		printf("%ld",nu(0));
	}
	freopen("migrate.out","w",stdout);
	return 0;
}
