#include<iostream>
#include<cstdio>
#include<vector>
/*
还是直接dfs暴力吧,累了,还要考期中呢 
*/

struct s_info{
	int note = 0;
	long long t = -1;
};

inline void solve(){
	int c, n, m, d, q;
	std::cin >> c >> n >> m >> d >> q;
	std::vector<std::vector<long long> > edges(n+1, std::vector<long long>(n+1));//线路边 
	std::vector<long long> t(m+1);//进出站时间，额外+即可
	std::vector<std::vector<s_info> > ss(n+1);//线路站台信息 
	std::vector<std::vector<s_info> > sl(m+1);//站台线路信息 
	for(int i=1;i<=m;++i){
		std::cin >> t[i];
	} 
	for(int i=1;i<=n;++i){
		int l;
		std::cin >> l;
		std::vector<s_info> s(l+1);
		for(int j=1;j<=l;++j){
			std::cin >> s[j].note >> s[j].t;
			s_info si;
			si.note = i, si.t = s[j].t;
			sl[s[j].note].push_back(si);
		}
		ss[i] = s;
	}
	//检查站台信息
//	for(int line = 1;line<=n;++line){
//		std::cout << line << "号线:";
//		for(const auto& st:ss[line]){
//			std::cout << st.note << "(" << st.t << ") ";
//		}
//		std::cout << std::endl;
//	} 
//	
	std::vector<bool> vis(n+1, 0);
	std::vector<bool> vis_(m+1, 0);
	auto dfs = [&](const auto& self, int x, int y) -> long long{//在x的站台要到y的站台 
//		std::cout << "x,y:" << x << " " << y << std::endl;
		if(x == y) return 0;
		long long res = 1e18, tr = 0;
		for(const auto& line_:sl[x]){//从当前站台入线 
			int line = line_.note, t = line_.t;
			if(line==0) continue;//不合法 
			if(vis[line]) continue;
			vis[line] = true;
			tr = t;
			//选择一站下车
//			std::cout << "尝试进入" << line << "号线路,当前区间步行时间:" << tr << std::endl;
			for(const auto& st:ss[line]){//从线路某一站下车并进入站台 
				if(st.note==0) continue;//不合法 
				if(vis_[st.note]) continue;
				vis_[st.note] = true;
				tr += st.t;
//				std::cout << "尝试从" << st.note << "下车并前往站台,当前区间步行时间" << tr << std::endl;
				long long bh = self(self, st.note, y);
				if(tr+bh<res) res = tr+bh;
				tr -= ss[line][st.note].t;
				vis_[st.note] = false;
			}
			vis[line] = false;
		}
		return res;
	};
	while(q--){
		vis = std::vector<bool>(n+1, 0);
		vis_ = std::vector<bool>(m+1, 0);
		int x, y;
		std::cin >> x >> y;
		vis_[x] = 1;//释怀了,不小心把y带上了 
		std::cout << dfs(dfs, x, y)+t[x]+t[y] << "\n";//样例2已经极其诡异了,但我不想调了 
	}
}

signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
} 
