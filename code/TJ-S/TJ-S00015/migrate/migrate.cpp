#include<iostream>
#include<cstdio>
#include<vector>
/*
A...B...C...D
A->C,A!->D,B->D,d(AC)=D(BD) 
恰好包含一对AD的路径为所求.如果AC间有多个B,那就对应多个D,就不行 
考虑万一B能飞过D,对于A->D+1会错误统计吗?会,因为AD意味着有相同长度的不同路径,不保证最短,所以一会儿还得算最短路?能不能直接特殊处理所有D+点？
重新考虑,恰好包含一对AD且l-t为最短路径长度的区间为所求.求最短路径长度是最直接的办法

复杂度爆炸,只能骗分 
*/
struct unit{
	int A = -1, D = -1, t = -1;//t为节省长度,即A->C 注意AC跳是把t->1而非t->0 
};

inline void solve(){
	int n, d;
	std::cin >> n >> d;
	std::vector<int> x(n), y(n-1), z(n-2);
	for(int i=0;i<n;++i){
		std::cin >> x[i];
		if(i>0){
			y[i-1] = x[i]-x[i-1];
			if(i>1){
				z[i-2] = y[i-1]-y[i-2];
			}
		}
	}
	std::vector<unit> us;
	std::vector<int> js(n, -1);
	for(int i=0;i<n-2;++i){
		if(z[i]>d) continue;
		//可能为A z[i]对应从i->i+2
		//接下来求C(最短->最远)
		int j = i+2, cd = z[i];
		while(cd<=d){
			if(j+2>=n) break;
			if(cd+y[j]<=d){
				cd += y[j++];
				continue;
			}
			break;
		}
		js[i] = j;
		if(j==n-1) continue;//C后面不可能有D了 
		//i->j
		int ni = i+1, nj = j+1;
		while(nj<n){
			if(cd-y[ni-1]+y[nj]){//nj为D
				unit u;
				u.A = i, u.D = nj, u.t = j-i;
				us.push_back(u);
				++ni, ++nj; 
				continue;
			} 
			break; 
		}
	}
	//ADt求完求最短路,期间最大跳跃如果有重叠就都试试,没有就直接用?也需可以dp?好像不太行.贪心反悔好像就可以(不可以,如果出现A-B-C-D-e,A->C,B->D,C->E,可能A->C->E最优但取到B->D),
	//按开头取,如果一个跳跃没结束就到下一个就比谁长
	auto get_dis = [&](int i, int j){
		int res = 0;
		int ni = i;//当前位置 
		int jump = -1;//-1表示当前不在跳跃,否则表示当前跳跃起点
		int tar = -1;//-1表示当前不在跳跃,否则表示当前跳跃终点
		int killed_jump = -1;//补丁：还是不行,如果出现冲突链还得死,但是就这样吧 
		int killed_tar = -1; 
		for(;ni<=j;++ni){
//			std::cout << "dis计算" << ni << " " << res << " " << tar << std::endl;
			if(ni==tar){//一个跳跃结束了(结束结算res) 
				++res;
				jump = tar = -1;
//				std::cout << "A";
			}
			if(js[ni]==-1){//当前不能跳跃 
				if(jump==-1){//现在也不在跳跃中 
					++res;
//					std::cout << "B";
				}
//				std::cout << "C";
				continue;
			}
			if(jump == -1){//当前能跳跃且不在跳跃中 
				jump = ni, tar = js[ni];
//				std::cout << "D" << tar << "\n";
				continue;
			}
			//冲突
			if(js[ni]-ni>tar-jump){//新跳跃更优
//				std::cout << ni << " " << js[ni] << " " << jump << " " << tar << std::endl;  
				//检查killed_jump能否恢复
				if(killed_jump!=-1){
					if(killed_tar<=ni){//可以恢复 
						//旧跳跃还没结算,按未跳跃结算,死跳跃已经结算(取消),回溯
						res += ni-jump-(killed_jump-killed_tar+1);
						killed_jump = jump;//嵌套链hack点 
						killed_tar = tar;
						jump = ni;
						tar = js[ni];
//						std::cout << "E";
						continue;
					}
//					std::cout << "F";
				} 
				//干掉旧跳跃 
				res += ni-jump;
				killed_jump = jump;
				killed_tar = tar;
				jump = ni;
				tar = js[ni];
//				std::cout << "G";
			} 
//			std::cout << "H";
		}
		return res; 
	};
	long long ans = 0;
	std::vector<std::vector<int> > dis(n, std::vector<int>(n));
	for(int i=0;i<n;++i){
		for(int j=i+3;j<n;++j){//长度小于3的结构无法构成ABCD 
			dis[i][j] = get_dis(i, j);
//			std::cout << dis[i][j] << " " << i << " " << j << std::endl; 
			//找到最长的AD,检查唯一性,然后再检查最长性
			int nu = 0;
			unit mu;
			for(const auto& u:us){
				if(u.D>j) break;
				if(u.A<i) continue;
				if(u.t>mu.t){
					nu = 1;
					mu = u;
					continue;
				}
				if(u.t==mu.t){
					++nu;
				}
			}
//			std::cout << nu << " " << mu.t << std::endl;
			if(nu!=1) continue;
			if(j-i-mu.t+1==dis[i][j]) ++ans;
		}
	}
	std::cout << ans << "\n";
}

signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	freopen("migrate.in","r",stdin);//力竭了.第一个样例都没过,再挣扎7分钟 好了没时间了 
	freopen("migrate.out","w",stdout);
	int c, T;
	std::cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
}
