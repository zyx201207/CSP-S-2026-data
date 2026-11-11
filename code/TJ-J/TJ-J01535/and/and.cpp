#include<bits/stdc++.h>
using namespace std;
 long long n,m,a[2000001],b[2000001],l,ma,z,q,o[5];
 int main(){
 freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	scanf("%lld%lld",&n,&m);
 	for(int i=1;i<=n;i++){
 		scanf("%lld",&a[i]);
 		q=max(q,a[i]);
	 }
	 sort(a+1,a+n+1);
	 if(m==1){
	 	printf("%lld",a[n]);
	 	return 0;
	 }
 	if(m==n){
 		l=a[1];
 		for(int i=2;i<=n;i++){
 			l=l&a[i];
		 }
		 printf("%lld",l);
		 return 0;
	 }
	 if(m==2){
	 	for(int i=1;i<n;i++){
	 		for(int j=i+1;j<=n;j++){
	 			ma=max(ma,a[i]&a[j]);
			 }
		 }
		 printf("%lld",ma);
		 return 0;
	 }
	 if(n<=300){
	for(int i=1;i<=n;i++){
		l=a[i],b[i]=1;
		int y=1,ma=0,mi=0;
		while(y<m){
			ma=0,mi=0;
			for(int j=1;j<=n;j++){
				if(l&a[j]>ma&&b[j]==0){
					ma=l&a[j];
					mi=j;
				}
			}
			l=ma;
			b[mi]=1;
			y++;
		}
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
		z=max(z,l);
	}
	printf("%lld",z);
	return 0;
}
if(q<=4){
	for(int i=1;i<=n;i++){
		o[a[i]]++;
	}
	if(o[4]>=m){
		printf("%d",4);
		return 0;
	}
	else{
		if(o[3]>=m){
			printf("%d",3);
			return 0;
		}
		else{
			if(o[3]+o[1]>=m){
				printf("%d",3);
			}
			else{
				if(o[3]+o[2]>=m){
					printf("%d",2);
				}
				else{
					printf("%d",0);
				}
			}
		}
	}
}
else{
l=a[n];
for(int j=1;j<m;j++){
	l=l&a[n-j];
}
printf("%lld",l);
}
return 0;
 }
