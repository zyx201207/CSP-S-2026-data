#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],bucket[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		scanf("%d",a+i);
	for(int i=n-1; i>=0; i--) {
		bucket[a[i]]++;
		if(bucket[a[i]]==2)
			a[i]=0;
	}
	for(int i=0; i<n; i++) ans[a[i]]++;
	for(int i=1; i<n; i++)
		for(int j=i; j<n; j++) ans[a[i]]++;
	for(int i=1; i<=m; i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
