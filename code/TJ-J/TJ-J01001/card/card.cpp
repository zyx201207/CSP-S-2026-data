#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001];
int b[300001],top;
int main(){
	freopen("card3.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[++top]=a[j];
			for(int k=1;k<top;k++)
				if(a[j]==b[k])
					top=k;
		}
		top++;
		for(;--top;)
			ans[b[top]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
}
