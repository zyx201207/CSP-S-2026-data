#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//编号 线路数 站数 最多几条线 计划数
int walk[100005];
struct p{
	int stop;
	int cost;
}a[505][100005];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>walk[i];
	}
	for(int i=1;i<=n;i++){
		int num=0;
		cin>>num;//这个线路经过了多少站
		for(int j=1;j<=num;j++){
			cin>>a[i][j].line>>a[i][j].cost;
		}
	}
	if(c<=6){//前6个测试点，尝试用暴力
		for(int i=1;i<=q;i++){
			int start,endd;
			cin>>start>>endd;
			int min=-0xff;

		}
	}else if(7<=c&&c<=11){//特殊性质A:每个站最多2条线
		for(int i=1;i<=q;i++){
			int start,endd;
			cin>>start>>endd;
			int min=-0xff;
			for(int j=1;j<=m;j++){
                if(a[i][j].stop==start){

                }
			}
		}
	}else if(12<=c&&c<=19){//特殊性质B:步行时间相同
		for(int i=1;i<=q;i++){
			int start,endd;
			cin>>start>>endd;
			int min=-0xff;
			for(int j=1;j<=m;j++){
                if(a[i][j].stop==start){

                }
			}
		}
	}
	return 0;
}