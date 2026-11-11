#include<bits/stdc++.h>
using namespace std;\
int n,m,nm[500007],la[300007],qzh[500007],ans[300007],tzcs[300007];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
		scanf("%d",&nm[i]);
		if(la[nm[i]]==0)la[nm[i]]=i;
		tzcs[nm[i]]=i;
	}
    for(int i=1;i<=n;i++){
		int u=nm[i];
		qzh[i]--;
		qzh[tzcs[u]]++;
	}
	for(int i=1;i<=n;i++){
		qzh[i]+=qzh[i-1];
		ans[nm[i]]+=(qzh[i]+i);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}printf("\n");
    return 0;
}
