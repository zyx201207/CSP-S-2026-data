#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],to[500005],lst[300005],le[500005],c[500005];
stack<int>sta;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)to[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(lst[a[i]])to[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	bool pd=1;
	for(int i=1;i<=n;i++){
		if(to[i]!=i&&to[i]!=i+1){
			pd=0;
			break;
		}
	}
	if(pd){
		for(int i=1;i<=n;i++){
			if(a[i-1]!=a[i])ans[a[i]]+=i;
			else ans[a[i]]++;
		}
		for(int i=1;i<=m;i++)printf("%d ",ans[i]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(to[j]==j){
				ans[a[j]]++;
				j++;
			}else j=to[j];
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}


