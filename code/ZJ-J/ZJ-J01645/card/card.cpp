#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],p[M],c[N],ans[M];
bool v[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(c[j]>=i&&v[a[j]]==1)
				for(int x=c[j]+1;x<j;x++)v[a[x]]=0;
			v[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(v[j])ans[j]++;
		}
	}
	for(int i=1;i<m;i++){
		printf("%d ",ans[i]);
	}
	printf("%d",ans[m]);
	return 0;
}