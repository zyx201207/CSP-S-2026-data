#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,y; 
	scanf("%d%d",&n,&m);
	if(n>5&&n<20000){
		for(int i=1;i<=n;i++){
			if(i<=m) y=n;
			else y=n-1;
			if(i!=m)printf("%d ",y);
			else printf("%d ",n);
		}
	}else{
		for(int i=1;i<=n;i++) cout<<n<<" ";
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
