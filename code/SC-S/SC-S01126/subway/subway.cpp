#include<bits/stdc++.h>
using namespace std;
//priority_queue
vector<int>zhan;//地铁口到站厅的耗时
vector<vector<int>>juli;//每条线路经过的站的编号
vector<vector<int>> timi;//每条线路的时间
vector<int>qidi;//起点
vector<int>zodi;//终点
int mmm[50005];//标记每个站的经过线路数量
vector<int> mum[50005];//第i个数组存放经过第i个地铁站的线路的编号
int c,n,m,d,q;//输入的第一行包含五个非负整数c,n,m,d,q，分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int bfs(int from,int to,int sum,vector<int> a){//from初始站，to结束线路，sum目前耗费时间，a为已经经过的线路
	int maxx=0;
	for (auto i:mum[from]){//mum[from]表示经过初始站的所有线路
		bool tof=false;
		if (from==to){
			return sum;
		}
		for (auto j:a){
			if (i==j){
				tof=true;
				break;
			}
		}//排除已经去过的地铁线路
		if (tof)continue;
		a.push_back(i);
		
		for (auto z=0;z<juli[i].size();z++){
			if (juli[i][z]==from){
				sum+=timi[i][z];
			}
			if (mmm[juli[i][z]]>1){
				maxx=max(bfs(juli[i][z],to,sum+timi[i][z],a),maxx);
			}
		}
		
	}
	return maxx;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//读入基础信息
	for(int i=0;i<=n;i++){
		int k;
		cin>>k;
		vector<int> ll;//经过的地铁站
		vector <int> rr;//时间
		for (int j=0;j<2*k;j++){
			int uiui;
			cin>>uiui;
			ll.clear();
			rr.clear();
			if (j%2==0){
				ll.push_back(uiui);
				mum[uiui].push_back(j/2);
				mmm[uiui]+=1;
			}
			if (j%2==1){
				rr.push_back(uiui);
			}
		}
		juli.push_back(ll);
		timi.push_back(rr);
	}//读入每个线路
	for (int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		qidi.push_back(l);
		zodi.push_back(r);
	}//读入每个问题
	vector<int> yiui;
	for (int i=0;i<q;i++){
		cout<<bfs(qidi[i],zodi[i],0,yiui)<<" ";
	}
	return 0;
}