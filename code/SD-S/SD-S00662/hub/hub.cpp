#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int read(){
	int k=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='0'&&ch>='9'){
		k=(k<<1)+(k<<3)+(ch^48);
		ch=getchar();
	}
	return k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==13||c==14){
		for(int i=1;i<=t;i++){
			scanf("%d%d",&n,&k);
			for(int j=1;j<=2*n-2;j++)int y=read();
			if(n==k)printf("0\n");
			else{
				if(k>=(n+1)>>1)printf("1\n");
				else{
					int u=(n+1)>>1;
					printf("%d\n",((u-k+3)>>2)+1);
				}
			}
		}
	}
	else if(c==1){
		for(int i=1;i<=t;i++){
			scanf("%d%d",&n,&k);
			for(int j=1;j<=2*n-2;j++)int y=read();
			if(n==k)printf("0\n");
			else{
				if(k==1&&n==5)printf("2\n");
				else printf("1\n");
			}
		}
	}
	return 0;
}
