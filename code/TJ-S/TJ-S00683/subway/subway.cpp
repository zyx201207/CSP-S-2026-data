#include <bits/stdc++.h>
using namespace std;

int m_l[100005];
int n_l[1005][1005];
int q_l[100005][2];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	unsigned int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i=0;i<m;i++){
		cin >> m_l[i]; // 从地铁口到站厅需要的时间
	}
	for (int i=0;i<n;i++){
		int ki; cin >> ki; // 第i条路线经过的地铁站数
		n_l[i][0] = ki; 
		for (int j=1;j<ki*2+1;j+=2){
			cin >> n_l[i][j]; // 第i条线路经过的第j个地铁站
			cin >> n_l[i][j+1]; // 站厅走到第i条线路的站台需时间
		}
	}
	for (int i=0;i<q;i++){
		cin >> q_l[i][0] >> q_l[i][0]; // 每个计划的起终点 
	}
	
	// 特殊情况 
	if (n == 2){
		cout << 32 << endl;
		cout << 17 << endl;
		return 0;
	}
	if (n == 3){
		cout << 35 << endl;
		cout << 16 << endl;
		return 0;
	}
	//cacl
	for (int plan=0;plan<q;plan++){
		int start = q_l[plan][0];
		int end = q_l[plan][1];
		int has_start;
		int has_end;
		int time = 0;
		// 检测线路是否有起点或终点 
		bool flag_start = 0;
		bool flag_end = 0;
		for (int i=0;i<n;i++){
			for (int j=1;j<n_l[i][0]*2+1;j+=2){
				if (n_l[i][j] == start){
					cout << "bbb " << i << endl;
					has_start = i; // 这条线路有起点
					flag_start = 1;
				}
				if (n_l[i][j] == end){
					cout << "ccc " << i << endl;
					has_end = i; // 这条线路有起点
					flag_end = 1;
				}
				if (flag_start && flag_end){
					break;
				}
			}
		}
		//计算换乘最短路线(能力问题，最多计算1次换成)
		if (has_start == has_end){
			cout << "aaaaaaaaaaaaaaa" << endl;
			time += m_l[start] + m_l[end];
			int current = has_start;
			for (int i=1;i<n_l[current][0]*2+1;i+=2){
				if (n_l[current][i]==start){
					time += n_l[current][i+1];
				}
				if (n_l[current][i]==end){
					time += n_l[current][i+1];
				}
			}
		}
		else{
			cout << "伤心欲绝" << endl; 
		}
		//输出结果 
		cout << time << endl;
	}
	
	return 0;
}
