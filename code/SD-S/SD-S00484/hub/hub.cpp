#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,f;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	f=t;
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
		}
		printf("%d\n",abs(c*t+c+n*(k-1)-abs(5-t)*(2*(f-t-1)+1)-3*(f-t-1)));
	}
	return 0;
}

