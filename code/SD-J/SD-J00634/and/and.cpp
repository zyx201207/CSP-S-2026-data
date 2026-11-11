#include<bits/stdc++.h>
using namespace std;
int n,m,a[210000],ans,maxx;
void dfs(int x,int ans,int cnt){
	if(cnt==m+1){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=x;i<=n;i++){
		if(x==1){
			dfs(i+1,a[i],cnt+1);
		}
		dfs(i+1,ans&a[i],cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		printf("%d",maxx);
	}
	else if(n<=20){
		dfs(1,0,1);
		printf("%d",maxx);
	}
	else if(m==n){
		int num=0;
		for(int i=1;i<=n;i++){
			num&=a[i];
		}
		printf("%d",num);
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					maxx=max(maxx,a[j]&a[i]);
				}
			}
		}
		printf("%d",maxx);
	}
	return 0;
}
