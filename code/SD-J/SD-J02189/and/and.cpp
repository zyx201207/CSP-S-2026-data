#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0,z=1000;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		x=max(x,a[i]);
		z=min(z,a[i]);
	}
	if(m==1){
		printf("%d",x);
		return 0;
	}
	if(m==n){
		printf("%d",z);
		return 0;
	}
	printf("%d",a[n-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
