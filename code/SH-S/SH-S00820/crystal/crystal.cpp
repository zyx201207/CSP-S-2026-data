#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000000],b[1000000],c[5],t;
long long f[10000][100]={m};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);}
	  	for(int i=1;i<=n;i++){
	  		for(int j=1;j<=n;j++)
	  		if(a[i]<a[j]) {
	  			int p=a[i];
	  			a[i]=a[j];
	  			a[j]=p;
			  }
		  }
	
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++)
		f[i][0]=1;
	for(int i=1;i<=n;i++){
		int e=f[i-1][0];
		for(int j=1;j<=e;j++){
			if(f[i][j]>=b[i]){
		f[i][0]=f[i][0]+1;
		f[i][j]=f[i][j]-b[i];
		}
	}
		}
		t=1;
	for(int i=1;i<=n;i++){
		if(f[i][0]>t) t=f[i][0];
	}
	printf("%d",t);
			return 0;
		}
	

