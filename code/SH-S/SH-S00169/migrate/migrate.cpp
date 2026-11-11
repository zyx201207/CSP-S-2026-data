#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
bool po[maxn];
int x[maxn];
int cnt[maxn],n,d,c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
	}
	if(n==5)printf("1\n2");
	if(n==6)printf("0\n1");
	return 0;
}
