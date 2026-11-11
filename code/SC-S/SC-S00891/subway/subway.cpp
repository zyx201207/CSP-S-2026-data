#include<bits/stdc++.h>
using namespace std;
struct qwe{
	int q,w;
}a[10000][10000];
int c,n,m,d,q,asd[10000][10000];
queue<pair<int,int>>qw;
bool qwer[1000][1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>c;
		for(int j=1;j<=n;j++)a[j][i].q=c;
	}
	for(int i=1;i<=n;i++){
		cin>>c;
		int y,u;
		for(int j=1;j<=c;j++)cin>>y>>u,a[i][y].w=u;
	}
	for(int i=1;i<=q;i++){
		int y,u,k=1e9,h;
		cin>>y>>u;
		for(int j=1;j<=n;j++)if(a[j][y].w!=0&&a[j][y].w<k)k=a[j][y].w,h=j;
		qw.push({h,y});
		int as=0;
		while(!qw.empty()){
			int z=qw.front().first,x=qw.front().second;
			if((z==h&&x==y)||x==u){
				asd[z][x]=a[z][x].q+a[z][x].w;
				
			}
			else asd[z][x]=a[z][x].w;
			as+=asd[z][x];
			
			qw.pop();
			if(a[z][x+1].w!=0&&!qwer[z][x+1])qw.push({z,x+1}),qwer[z][x+1]=1;
			if(a[z+1][x].w!=0&&!qwer[z+1][x])qw.push({z+1,x}),qwer[z+1][x]=1;
			if(a[z-1][x].w!=0&&!qwer[z-1][x])qw.push({z-1,x}),qwer[z-1][x]=1;
		}
		cout<<as<<"\n";
	}
	return 0;
}