#include<bits\stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
int k[300010];
int t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		k[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t=a[j];
			ans[t]++;
			j=k[t];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
