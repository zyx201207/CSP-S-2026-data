#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50005];//地铁口到站厅   时间
int k[505];//线路经过     地铁站数
int a[505][505];//线路i经过的第j个地铁站
int t[505][505];//地铁站的站厅走到第i条线路的站台需要的时间
int x[100005];
int y[100005];
struct node{
	int stt;
	int time;
};
vector<int> v;
bool dchc=0;//多次换乘 

bool b=0;
int memory_i=0;
int x_j=0;
int y_j=0;
int sum=0;


int ai,aj,bi,bj;
bool cmp_huancheng(int r){
	
	for(int i=1;i<=n;i++){//(i,j)(x,y)
		if(b==1){
			break;
		}
		for(int j=1;j<=k[i];j++){	
			if(a[i][j] == x[r]){
				memory_i=i;
				x_j=j;
			}
			if(a[i][j] == y[r]){
				bi=i;bj=j;
				if(memory_i == i){
					y_j=j;
					b=1;
				}else{
					sum=abs(memory_i-i);
					if(sum > 1){
						dchc=1;
					}else{
						v.push_back(t[memory_i][j]+t[i][x_j]);
					}
				}
			}
			if(b==1){
				break;
			}
		}
	}
	return b;
}
void find_huancheng(){
	for(int i=1;i<=n;i++){//(i,j)(x,y)
		for(int j=1;j<=k[i];j++){	
			for(int x=i+1;x<=n;x++){
				for(int y=1;y<=k[x];y++){
					if(a[i][j] == a[x][y]){
						clog << 1;
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
	for(int i=1;i<=m;i++){
		cin >> w[i];//每个地铁站的地铁口走到站厅需要的时间
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];//第i条线路经过的地铁站数
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			//ai,j  表示第i条线路经过的第j个地铁站
			//ti,j  表示从该地铁站的站厅走到第i条线路的站台需要的时间
		}
	}
	for(int r=1;r<=q;r++){
		cin >> x[r] >> y[r];//第r 个出行计划的起点和终点所在的地铁站编号
		if(cmp_huancheng(r)){
			cout << w[x[r]]+t[memory_i][x_j]+w[y[r]]+t[memory_i][y_j]<<endl;
		}else{
			if(dchc==0){
				int minn=INT_MAX;
				for(int i=0;i<v.size();i+=1){
					minn=min(minn,(v[i]));
				}
				cout << w[x[r]]+t[memory_i][x_j]+w[y[r]]+t[bi][bj]+minn << endl;
			}else{
				
			}
		}
	}
	return 0;
} 
/*
1 2 5
2 3 7
3 5 4 6
*/
