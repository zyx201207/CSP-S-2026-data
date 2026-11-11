#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)scanf("%d",&c);
		int m=(n-1)/2;
		int ans=ceil((m-k)*1.00/4)+1;
		printf("%d\n",ans);
	}
	return 0;
}
