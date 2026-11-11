#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],pos[N],stk[N],top;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int l=1;l<=n;l++){
		top=0;
		memset(pos,-1,sizeof pos);
		for(int i=l;i<=n;i++){
			if(pos[a[i]]==-1){
				pos[a[i]]=++top;
				stk[top]=a[i];
				continue;
			}
			top=pos[a[i]];
		}
		for(int i=1;i<=top;i++){
			cnt[stk[i]]++;
			printf("%d%c",stk[i],i==top?'\n':' ');
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d%c",cnt[i],i==m?'\n':' ');
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
}
//ccf please let me AC!!!
