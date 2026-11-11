#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,x[N];
bool p=1;
int main(){
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	scanf("%d %d",&c,&t);
	while (t--){
		long long n,d;
		scanf("%d %d",&n,&d);
		for (int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for (int i=1;i<=n-1;i++){
			if (x[i+1]-x[i]>d)
				p=0;
		}
		if (p==0){
			printf("%d\n",0);
			continue;
		}
		printf("%d\n",1);
	}
	return 0;
}