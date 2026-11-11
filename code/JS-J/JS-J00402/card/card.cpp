#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]!=a[i-1]){
			ans[a[i-1]]=i-1;
		}
	}
	ans[m]=n;
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
}
