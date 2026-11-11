#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int a[N],ans,n,m;
bool v[N];
void dfs(int u,int sum,int now){
	v[u]=true;
	int t=now&a[u];
	if(now!=-1&&t<=ans){
		v[u]=false;
		return ;
	}
	if(sum==m){
		ans=max(ans,t);
		v[u]=false;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			if(now==-1) dfs(i,sum+1,a[i]);
			else dfs(i,sum+1,t);
		}
	}
	v[u]=false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0,0,-1);
	printf("%d",ans);
	return  0;
}//·´ÎÚÍÐ°î 
