#include<bits/stdc++.h>
using namespace std;
int cnt[500050],a[500050],top,idx[500050];
bool f=0;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(a[i]<a[i-1]) f=1;
	}for(int i=1;i<=n;i++) {
		top=0;
		memset(idx,0,sizeof(idx));
		for(int j=i;j<=n;j++) {
			if(idx[a[j]]==0) idx[a[j]]=++top;
			else {
				top=idx[a[j]];
				for(int k=1; k<=m; k++)
					if(idx[k]>idx[a[j]]) idx[k]=0;
			}
		}for(int j=1;j<=m;j++)
			if(idx[j]!=0) cnt[j]++;
	}for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
