#include<bits/stdc++.h>
using namespace std;
int a[500005],Q[300005],ans[300005],f[500005],to[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		Q[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		f[i]++;
		to[Q[a[i]]+1]++;
	}
	for(int i=1;i<=n;i++){
		f[i]+=to[i];
		to[Q[a[i]]+1]+=to[i];
	}
	for(int i=1;i<=n;i++) ans[a[i]]+=f[i];
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}