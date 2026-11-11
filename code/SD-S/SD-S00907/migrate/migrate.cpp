#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int c,t,n;
int m;//记录可能路径 
long long d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%d%lld",&n,&d);
		m=0;
	for(int j=1;j<=n;j++){
		scanf("%lld",&x[j]);
	}
    for(int k=1;k<=n;k++){
    	if(x[k]+d+1==x[k+d+1]){
    		m++;
		}
	}
	if(d==2){
	printf("%d",m);
}else{
	printf("%d",0);
}
}
	return 0;
}
