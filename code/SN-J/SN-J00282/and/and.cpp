#include <bits/stdc++.h>
using namespace std;
int n,m,maxa=0;
long long a[200005],c[200005];
inline void dfs(int p,int x){
	if(x==m){
		int cnt,f=0;
		for(int i=1;i<=p;i++){
			if(c[i]!=0 && f==0){
				f=1;
				cnt=c[i];
			}
			else if(c[i]!=0){
				cnt&=c[i];
			}
		}
		maxa=max(maxa,cnt);
		return;
	}
	else if(p==n){
		return;
	}
	c[p]=a[p];
	dfs(p+1,x+1);
	c[p]=0;
	dfs(p+1,x);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	printf("%d",maxa);
	return 0;
}

