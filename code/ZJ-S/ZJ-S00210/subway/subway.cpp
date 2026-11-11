#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int z=1e9;

int sum;//所需的总时间
int c,n,m,d,q;//测试点,地铁线路数,地铁站数
vector <pair<int,int>> v(m+5);
int w[500005];//每个地铁站到站台的时间
int k[1001];//第i条线路经过几个站台
int a[205][2500];//a[i][j]表示第i条线路经过的第j个地铁站是哪个
ll t[205][1005];//t[i][j]表示第j个地铁站站厅到第i条线路的站台所需时间
int x_i,x_j;//起点位于那一条线路
int y_i,y_j;//终点位于哪一条线路
int mid_j1,mid_j2,mid_i1,mid_i2;
int num[50005];
int mid;//重合的站台有哪些
void deal(int x,int y){
	sum+=w[x];//从地铁站到站厅
	sum+=t[x_i][x_j];
	sum+=w[y];
	if(y==a[mid_i1][mid_j1]&&(y_i==mid_i1&&y_j==mid_j1||y_i==mid_i2&&y_j==mid_j2)){
		if(x_i==mid_i1){//重合的情况
			sum+=t[mid_i1][mid_j1];
		}
		else if(x_i==mid_i2){
			sum+=t[mid_i2][mid_j2];
		}
	}
	else if(x_i!=y_i){//非重合即起点与终点不能直达
		sum+=t[mid_i1][mid_j1];
		sum+=t[mid_i2][mid_j2];
		sum+=t[y_i][y_j];
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
			num[a[i][j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(num[i]>1){
			mid=i;
		}
	}

	
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
			for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				x_i=i;//起点线路
				x_j=j;
			}
			if(a[i][j]==y){
				y_i=i;//终点线路
				y_j=j;
			}
			if(a[i][j]==mid&&i==1){
				mid_i1=i;
				mid_j1=j;
			}
			else if(a[i][j]==mid&&i==2){
				mid_i2=i;
				mid_j2=j;
			}
		}
	}
		deal(x,y);
		
		cout<<sum<<endl;
		sum=0;
	}

	return 0;
}