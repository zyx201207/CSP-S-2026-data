#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int w[1001],k[501],t[501][501],m;
int f(int x,int y,int z){
	int minn=INF;
	for(int i=1;i<=m;i++){
		if(t[x][i]!=INF){
			if(i==y)return t[x][y];
			else if(i!=z){
				minn=min(t[x][i]+f(i,y,x),t[x][y]);
				break;
			}
		}
	}
	return minn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,d,q,tmp,x,xt,y,yt,sta,sto;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=0;i<=500;i++)memset(t[i],INF,501);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		cin>>tmp;
		scanf("%d %d %d %d",&x,&xt,&y,&yt);
		t[x][y]=min(yt+xt,t[x][y]);
		t[y][x]=min(yt+xt,t[y][x]);
	}
	for(int i=1;i<=q;i++){
		cin>>sta>>sto;
		printf("%d\n",w[sta]+w[sto]+f(sta,sto,0));
	}
}