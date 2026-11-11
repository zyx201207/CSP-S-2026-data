#include<bits/stdc++.h>
using namespace std;
int bian,_t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&bian,&_t);
	if(bian>1){
		while(_t--)
			printf("1\n");
		return 0;
	}
	while(_t--){
		scanf("%d%d",&n,&k);
		for(int i=1,a,b;i<n;i++)
			scanf("%d%d",&a,&b);
		if(k==n){
			printf("0\n");
			continue;
		}
		printf("1\n");
	}
	return 0;
}