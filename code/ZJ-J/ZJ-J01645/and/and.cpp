#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans=INT_MIN,ma=INT_MIN,sum;
void dfs(int s,int k,int j){
	if(k==m+1){
		ans=max(ans,s);
		return;
	}
	for(int i=j+1;i<=n;i++){
		if(k==1)dfs(a[i],k+1,i);
		else dfs(s&a[i],k+1,i);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i==1)sum=a[1];
			else sum=sum&a[i];
		}
		printf("%d",sum);
		return 0;
	}
	if(n==1){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ma=max(a[i],ma);
		}
		printf("%d",ma);
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(0,1,0);
	printf("%d",ans);
	return 0;
}