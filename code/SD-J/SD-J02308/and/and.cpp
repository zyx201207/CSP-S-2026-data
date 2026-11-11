#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
bool b[200005];
long long a[200005];
long long x,st;
long long ans;
void DFS(long long res,int cnt){
	if(cnt==m){
		ans=max(ans,res);
		return;
	} 
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			DFS(res&a[i],cnt+1);
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	x=1;
	for(int i=1;i<=32;i++){
		st+=x;
		x=x*2;	
	}
	DFS(st,0);
	printf("%lld",ans);
	return 0;
} 
