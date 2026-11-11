#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005];
long long ans,b[200005];
int re(long long x){
	long long y=0,i=1;
	while(x){
		y=y+x%2*i;
		i=i*10;
		x=x/2;
	}return y;
}
int an(long x,long y){
	long long p=x+y,pp=0,i=1;
	while(p){
		pp=((p%10)==2)*i+pp;
		i=i*10;
		p=p/10;
	}return pp;
}
int shi(long long x){
	long long y=0,i=1;
	while(x){
		y=y+x%10*i;
		i=i*2;
		x=x/10;
	}return y;
}
void dfs(int cnt,int xz){
	if(cnt==m){
		long long ans1=b[1];
		for(int i=2;i<=m;i++){
			ans1=shi(an(re(ans1),re(b[i])));
		}
		ans=max(ans,ans1);
		return;
	}
	for(int i=xz+1;i<=n;i++){
		b[cnt+1]=a[i];
		dfs(cnt+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(0,0);
	printf("%lld",ans);
}