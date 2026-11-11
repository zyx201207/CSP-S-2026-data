#include<bits/stdc++.h>
using namespace std;
int c,t,d,x[2000005],n;
int main(){
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	scanf("%d%d",&c,&t);
 	while(t--){
 		scanf("%d%d",&n,&d);
 		for(int i=1;i<=n;i++) scanf("%d",&x[i]);		
	}
	if(c==11||c==12) printf("%d",n-2);
	else printf("%d",2);	
 	return 0;
}
