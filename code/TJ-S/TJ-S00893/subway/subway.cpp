#include<bits/stdc++.h>
using namespace std;
struct station{//t站厅到站台时间，a经过的地铁站 
	int t;
	int a;
}k[510][5050];
int c,n,m,d,q;//c测试点编号、n地铁线路数、m地铁站数、d每个地铁站最多被几条线路经过 、q出行计划数 
int w[500050],k0[500050],x,y,ans;//w站口到站厅时间，k0地铁线标号，x计划起点，y计划终点 
int temp1=0,temp2=0,;
int sum=0;//计划总时间
int findway(int x0,int y0){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k0[i];j++){
			if(k[i][j].a==y0) temp1=j;
			else if(k[i][j].a==x0) temp2=j;
		}
		if(temp1!=0&&temp2!=0){
			ans=k[i][temp1].t+k[i][temp2].t;
			return ans;
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
	for(int i=1;i<=n;i++){
		cin>>k0[i];
		for(int j=1;j<=k0[i];j++){
			cin>>k[i][j].a>>k[i][j].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y; 
		sum=sum+w[x]+w[y]+findway(x,y);
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
} 
