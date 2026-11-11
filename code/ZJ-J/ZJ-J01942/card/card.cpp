#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
struct node{
	int d,las;
	bool clean;
}a[N];
int n,m,Las[M],LAS[N],ans[M];
bool f1,f2;
int Find(int x,int turn){
	if(x<turn)return 0;
	if(a[x].clean){
		a[x].las=Find(a[x].las,turn);
		return a[x].las;
	}else return x;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].d);
		LAS[i]=a[i].las=Las[a[i].d];
		Las[a[i].d]=i;
		if(a[i].d<a[i-1].d)f1=true;
	}
	if(!f1){
		for(int i=1;i<=n;i++)ans[a[i].d]=max(ans[a[i].d],i);
		for(int i=1;i<=m;i++)printf("%d ",ans[i]);
		printf("\n");
		return 0;
	}
	if(m==1){
		printf("%d\n",n);
		return 0;
	}
	if(m==2){
		ans[a[n].d]=n;
		int g=3-a[n].d,ddd=0;
		for(int i=n;i>=1;i--)if(a[i].d==g){ddd=i;break;}
		for(int i=1;i<=ddd;i++)
			if(a[i].d==g)ans[g]++;
		printf("%d %d\n",ans[1],ans[2]);
		return 0;
	}
	for(int turn=1;turn<=n;turn++){
		for(int i=1;i<=n;i++)a[i].clean=false,a[i].las=LAS[i];
		for(int i=turn;i<=n;i++){
			int fa=Find(a[i].las,turn);
			if(fa>0)for(int j=fa;j<=i-1;j++)a[j].clean=true;
		}
		for(int i=turn;i<=n;i++)
			if(!a[i].clean)ans[a[i].d]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
