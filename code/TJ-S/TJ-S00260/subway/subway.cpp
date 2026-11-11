#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector> 
using namespace std; 
long long sss,n,m,d,q;
long long a[1005][1005];
long long w[1000005];
long long b[1000005],c[1000005];
void dijkstra(int x){
	int minn=1e9,minnn;
	for(int i=1;i<=m;i++){
		if(i!=x)b[i]=b[a[x][i]];
		if(b[i]<minn){
			minn=b[i];
			minnn=i;
		}
	}
	c[minnn]=0;
	for(int i=1;i<=m;i++){
		minn=1e9;
		int minnnn;
		for(int j=1;j<=m;j++){
			if(c[j]!=0&&b[minnn]+a[minnn][j]<b[j]){
				b[j]=a[minnn][j]+b[minnn];
				if(b[j]<minn){
					minn=b[j];
					minnnn=j;
				}
			}
		}
		if(minn==1e9)return;
		minnn=minnnn;
		c[minnn]=0;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>sss>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)a[i][j]=1e9;
	if(sss<=11&&sss>=7){
		for(int i=1;i<=n;i++){
			int Z,x1,y1,x2,y2;
			cin>>Z>>x1>>y1>>x2>>y2;
			a[x1][x2]=a[x2][x1]=y1+y2;
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			for(int i=1;i<=n;i++)b[i]=c[i]=1e9;
			b[x]=c[x]=0;
			dijkstra(x);
			cout<<b[y]+w[x]+w[y]<<'\n';
		}
	}
	return 0;
} 
