#include<bits/stdc++.h>
using namespace std;
int n,m,f[300010],a[500010],x,t,w,i,j,wz,ans,q[500010],e[500010],sum,g[500010],y,ee[500010];
struct no{
	int x,y;
}b[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i],g[a[i]]+=i;
	for(i=n;i>=1;i--){
		wz++;
		if(f[a[i]]!=0){
			b[++w].x=f[a[i]]+1;b[w].y=wz;
			f[a[i]]=wz;
			x=b[w].x;e[w]=0;ee[w]=0;
			for(j=w-1;j>0;j--){
				if(!e[j])q[b[j].x]+=(wz-y),q[b[j].y+1]-=(wz-y);
				if(b[j].y>=x&&!e[j])e[j]=1;
				else if(b[j].y<x)e[j]=0,x=b[j].x;
			}
			y=wz;
		} 
		else f[a[i]]=wz;
	}
	for(j=1;j<=w;j++)if(!e[j])q[b[j].x]+=(wz+1-y),q[b[j].y+1]-=(wz+1-y);
	wz=0;
	for(i=1;i<=n;i++)q[i]+=q[i-1];
	for(i=n;i>=1;i--)g[a[i]]-=q[n-i+1];
	for(i=1;i<=m;i++)cout<<g[i]<<" ";
	return 0;
}
