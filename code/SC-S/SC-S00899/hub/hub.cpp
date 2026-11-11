#include<bits/stdc++.h>
using namespace std;
int n,c,t,k,flag[1000005],ans=100000000,maxx;
struct road{
	int u,v;
}a[1000005];
void g(int x,int y,int z){
	if(a[x].u==y){
		if(flag[a[x].v]){
			maxx=max(maxx,z);
			return;
		}
		if(a[x].v==0)return;
		g(a[x].v,x,z+1);
	}
	else{
		g(a[x].u,x,z+1);
		if(a[x].v!=y)g(a[x].v,x,z+1);
	}
}
void f(int x,int ma){
	if(x>k){
		ans=min(ma,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			g(i,0,0);
			flag[i]=1;
			f(i,max(maxx,ma));
			flag[i]=0;
		}
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int x,y;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			if(!a[x].u)a[x].u=y;
			else a[x].v=y;
			if(!a[y].u)a[y].u=x;
			else a[y].v=x;
		}
		f(1,0);
		printf("%d\n",ans);
	}
	return 0;
}