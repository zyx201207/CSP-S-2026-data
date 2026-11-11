#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	while(q--){
		int ans;
		for(int i=1;i<=n;i++)
			ans=rand()%N;
		printf("%d\n",ans);
	}
	return 0;
}
