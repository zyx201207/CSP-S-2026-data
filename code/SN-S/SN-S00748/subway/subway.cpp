#include<bits/stdc++.h>
using namespace std;
long long dpt[510][100010],dpa[510][100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//思路 二维数组处理各条线路，一条线到不了目标站点，跳到下一行并加换站时间。记得重置 
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	//输入 每个地铁站的地铁口走到站厅需要的时间
	for(long long i=1;i<=m;i++){
		cin>>dpt[0][i];
	}
	//循坏输入各线路 
	for(long long i=1;i<=n;i++){ 
		cin>>dpa[i][0];
		for(long long j=1;j<=dpa[i][0];j++){
			//输入 各线路数据 
			cin>>dpa[i][j]>>dpt[i][j];
		}
	}
	//依次处理出行计划 
	while(q--){
		long long x,y,i=1;
		cin>>x>>y;
		//进站时间 
		long long time=dpt[0][x];
		//寻找初始站线路 
		for(long long j=1;j<=m;j++){
			if(dpa[i][x]==0){
				i++;
			}
		}
		//开始遍历线路 
		for(long long k=1;k<=n;k++){
			//开加 
			for(long long j=1;j<=dpa[i][0];j++){
				if(dpa[i][j]<=y){
					time+=dpt[i][j];
				}
				else{
					i++;
				}		
			}
		}
		cout<<time+dpt[0][y]<<endl;
	}
	return 0;
} 
//感觉过的好懵逼口牙 
