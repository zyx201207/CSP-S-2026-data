#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int b[200005][35]={};
int n,m,a[200005]={},x,w=1;
int andn(int s,int e){
	int c[35]={},len=max(b[s][34],b[e][34]),num=0;
	for(int i=1;i<=len;i++){
		c[i]=(b[s][len-i+1]+b[e][len-i+1])/2;
	}
	for(int i=1;i<len;i++){
		num=(num+c[i])*2;
	}
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(&a[1],&a[n+1]);
	for(int i=1;i<=n;i++){
		x=a[i];w=1;
		while(x>0){
			b[i][w]=x%2;
			x=x/2;
			w++;
		}
		b[i][34]=w-1;
	}
	if(m==1){
		printf("%d",a[n]);
	}
	else if(m=n){
		for(int i=2;i<=n;i++){
			a[i]=andn(i-1,i);
		}
		printf("%d",a[n]);
	}
	else{
		int lz=a[1];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int ls=andn(i,j);
				if(ls>lz){
					lz=ls;
				}
			}
		}
		printf("%d",lz);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
