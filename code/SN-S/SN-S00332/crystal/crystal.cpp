//刘启安 SN-S00332 西北大学附属中学 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500002],ma=-1;
void bb(int x){
	int y=x;long long a0=0,a1=1;
	if(x>=n){
		ma=max(ma,a0);
		return;
	}
	if(x==0){
		ma=max(ma,a1);
		bb(x+1);
		return;
	}
	long long j=1,m1=m;
	while(m1>0){
		if((y-1)<0){
			ma=max(j,ma);
			bb(x+1);
			return;
		}
		if((a[x]-a[y-1])>m1){
			ma=max(j,ma);
			bb(x+1);
			return;
		}else{
			m1-=(a[x]-a[y-1]);
			j++;y--;
		}
	}
	ma=max(j,ma);
	bb(x+1);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	scanf("%ld%ld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%ld",&a[i]);
	} 
	for(int i=0;i<n;i++){
		for(int j=0,y;j<n;j++){
			if(a[j]>a[j+1]){
				 y=a[j];
				 a[j]=a[j+1];
				 a[j+1]=y;
			}
		}
	}
	bb(0);
	printf("%ld",ma);
	freopen("crystal.out","w",stdout);	
	return 0;
}
