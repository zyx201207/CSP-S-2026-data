#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500050],dis[500050],t[500050],nxt[500050],an[300050];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=n;i>=1;i--){
		nxt[i]=dis[a[i]];
		dis[a[i]]=i;
		t[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(nxt[i]) t[nxt[i]]+=t[i];
		else{
			t[i+1]+=t[i];
			an[a[i]]+=t[i];
		}
	}
	for(int i=1;i<=m;i++) printf("%lld ",an[i]);
	return 0;
}