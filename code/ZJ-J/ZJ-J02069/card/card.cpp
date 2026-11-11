#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) ans[a[i]-1]++;
	ans[a[n-1]-1]=n;
	for(int i=0;i<m;i++) printf("%d ",ans[i]);
	return 0;
}