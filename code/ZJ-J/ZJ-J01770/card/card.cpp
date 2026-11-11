#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int MAXM=3e5+10;
int n,m;
int a[MAXN],ans[MAXN];
int pos[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n,now;i;i--){
		if(!pos[a[i]])pos[a[i]]=i;
		now=pos[a[i]];
		while(now<=n){
			ans[a[now]]++;
			now=pos[a[now]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d",ans[i]);
		putchar(" \n"[i==m]);
	}
	return 0;
}