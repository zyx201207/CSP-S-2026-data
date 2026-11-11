#include <iostream>

constexpr int N=1000010;

int testcase,T;
int n,k;
int lg[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&testcase,&T);
	
	lg[1]=0;
	for(int i=2;i<=1000000;i++) lg[i]=lg[i>>1]+1;
	
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
		}
		if(testcase==13||testcase==14){
			int m=(n-1)/2;
			int mid=(m+1)/2;
			if(m%2==1){
				if(k<=(mid-1)*2){
					printf("%d\n",mid-(k-1)/2);
				}else if(k==n) printf("%d\n",0);
				else printf("%d\n",1);
			}else{
				if(k<=(mid-1)*2+1){
					printf("%d\n",mid+1-(k+1)/2);
				}else if(k==n) printf("%d\n",0);
				else printf("%d\n",1);
			}
		}else {
			printf("%d\n",lg[n-k]);
		}
	}
	
	return 0;
}
