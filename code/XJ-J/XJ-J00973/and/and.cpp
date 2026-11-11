#include<bits/stdc++.h>
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n];
	for(int b=0;b<n;b+=1) scanf("%d",&a[b]);
	int max=0;
	if(m==2){
		for(int c=0;c<n-1;c+=1){
			for(int d=c+1;d<n;d+=1){
				if((a[c]&a[d])>max) max=(a[c]&a[d]);
			}
		}
	}
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}