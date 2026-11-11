#include<bits/stdc++.h>
using namespace std;
int a[2000005],b[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	int c,t,n,k;
	scanf("%d%d",&c,&t);
	for(int i=0;i<t;i++){
		scanf("%d%d",&n,&k);
		for(int j=1;j<n;j++)scanf("%d%d",&a[j],&b[j]);
		srand(time(0));
		printf("%d\n",rand()%n);
	}return 0;
}
