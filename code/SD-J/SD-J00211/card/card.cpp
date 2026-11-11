#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e5+5;
int n,m;
int a[N];
int p[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=n;i>=1;i--){
		if(p[a[i]]){
			for(int j=1;j<=m;j++)
				if(j!=a[i]&&p[j]<=p[a[i]])p[j]=0;
		}
		else
			p[a[i]]=i;
		for(int j=1;j<=m;j++)
			if(p[j])ans[j]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

