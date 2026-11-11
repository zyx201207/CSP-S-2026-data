#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int card[500005],nxt[500005],it[300005],ans[300005];
int find(int xx){
	if(nxt[xx]==0)return xx;
	return nxt[xx]=find(nxt[xx]);
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&card[i]);
	for(int i=1;i<=n;i++){
		if(it[card[i]])nxt[it[card[i]]]=i;
		it[card[i]]=i;
	}
	for(int i=n;i>=1;i--){
		int p=i;
		while(p<=n){
			p=find(p);
			++ans[card[p]];
			p++;
		}
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}