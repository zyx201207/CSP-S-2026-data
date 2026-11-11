#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],tot,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int t=1;t<=n;t++){
		tot=0;
		for(int i=t;i<=n;i++){
		for(int j=1;j<=tot;j++){
			if(f[j]==a[i]){
				tot=j-1;
				break;
			}
		}
		f[++tot]=a[i];
		}
		for(int i=1;i<=tot;i++){
			ans[f[i]]++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
