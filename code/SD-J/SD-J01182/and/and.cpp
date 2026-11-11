#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[0]);
	ans=a[0];
	for(int i=1;i<n;i++) {
		scanf("%d",a+i);
		if(m) {
			m--;
			ans=ans&a[i];
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
