#include<bits/stdc++.h>
using namespace std;
int n,m,lst[300005],cnt[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(lst,0,sizeof(lst));
		for(int j=i;j<=n;j++){
			if(lst[a[j]]){
				for(int k=lst[a[j]];k<j;k++)lst[a[k]]=0;
			}
			lst[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(lst[j])cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
	return 0;
}
