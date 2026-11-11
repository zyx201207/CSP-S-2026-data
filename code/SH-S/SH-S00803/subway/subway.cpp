#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N],k[510],x,y,a[510][N],t[510][N],u[N]; 
int c,n,m,d,q;
void f(int time,int zk){
	for(int i=1;i<=n;i++){
		bool cnt=false;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==zk){
				cnt=true;
				break;
			}
		}
		if(cnt==true){
			for(int j=1;j<=k[i];j++){
				if(time+t[i][j]>u[a[i][j]]){
					return;
				}
				u[a[i][j]]=time+t[i][j];
			} 
			for(int j=1;j<=k[i];j++){
				f(time+t[i][j],a[i][j]);
			}
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	memset(u,0x3f3f3f,sizeof(u));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];//i条铁路到的j个站
			cin>>t[i][j];//i条铁路所到的j个站到站厅的时间 
		} 
	} 
	f(0,1);
	while(q--){
		int ans=0;
		cin>>x>>y;
		cout<<u[y]-u[x]+w[x]+w[y]<<endl;
	}
	return 0;
} 
