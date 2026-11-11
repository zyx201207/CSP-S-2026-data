#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500010],c[500010],ok[500010],ans[500010];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) ok[j]=0;
		int top=0;
		for (int j=i;j<=n;j++) {
			if (ok[a[j]]) {
				while (true) {
//					if (top<0) printf("%d %d\n",i,j);
					ok[c[top]]--;
					if (c[top]==a[j]) {
						top--;
						break;
					}
					top--;
				}
			}
			ok[a[j]]++;
			c[++top]=a[j];
		}
		while (top) {
			ans[c[top]]++;
			top--;
		}
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
