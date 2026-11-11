#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],vis[300005],ans[300005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=max(b[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			j=b[a[j]];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
