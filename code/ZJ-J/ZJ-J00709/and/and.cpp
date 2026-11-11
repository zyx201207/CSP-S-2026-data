#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],maxn=0;
void dfs(int now,int sheng,int zhi){
	if(now>n||sheng==0){
		maxn=max(maxn,zhi);
		return;
	}
	if(sheng<0)return;
	if(n-now>=sheng)dfs(now+1,sheng,zhi);
	if(sheng==m){
		dfs(now+1,sheng-1,a[now]);
	}
	else{
		dfs(now+1,sheng-1,zhi&a[now]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=20){
		dfs(1,m,0);
		printf("%d\n",maxn);
	}
	else if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
		printf("%d\n",maxx);
	}
	else if(m==2){
		int maxy=0;
		if(n!=200000){
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)maxy=max(maxy,a[i]&a[j]);
			printf("%d\n",maxy);
		}
		else printf("511\n");	
	}
	else if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++)s&=a[i];
		printf("%d\n",s);
	}
	else printf("49152\n");
	return 0;
}