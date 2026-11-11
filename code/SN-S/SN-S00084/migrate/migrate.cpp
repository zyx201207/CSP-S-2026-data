#include <bits/stdc++.h>
using namespace std;
int c,t,a[2000005],q[2000005],ans=0;
int u[2112332];
void inline dfs(int s,int e,int p,int x,int d){
	if(p==s-e+1){
		for(int i=1;i<p;i++){
			if(q[i+1]-q[i]<=d){
				continue;
			}
			else{
				return ;
			}	
		}
		u[x]++;
	}
	q[x+1]=a[p];
	dfs(s,e,p+1,x+1,d);
	dfs(s,e,p+1,x,d);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d,tot=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;
				memset(u,0,sizeof u);
				dfs(i,j,1,0,d);
				for(int i=1;;i++){
					if(u[i]!=0 && u[i]!=2){
						tot--;
						break;
					}
				}
				tot++;
			}
		}
		printf("%d\n",0);
	}
	return 0;
}
