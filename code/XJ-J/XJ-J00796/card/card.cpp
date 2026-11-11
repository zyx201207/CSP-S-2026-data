#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[5010],ans[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=b[j];
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
