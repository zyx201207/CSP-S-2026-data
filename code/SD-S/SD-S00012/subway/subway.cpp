#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char gc;
	while(gc>'9'||gc<'0'){
		if(gc=='-') f*=-1;
		gc=getchar();
	}
	while(gc<='9'&&gc>='0'){
		s=s*10+gc-'0';
		gc=getchar();
	}
	return s*f;
}
vector<vector<int> > v;
int dis[1005][1005];
int sddfghjgfdadsfhg,n,m,d,q;
int a[100010];
int main(){
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	sddfghjgfdadsfhg=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=100000000;
		}
	}
	bool flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k==2){
			int a1,t1,a2,t2;
			cin>>a1>>t1>>a2>>t2;
			dis[a1][a2]=t1+t2;
		}
	}
	if(flag1){
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<a[u]+a[v]+dis[u][v]<<endl;
		}
	}
}

