#include <iostream>
#include <queue>

int c, t, n;
long long d;
long long x[2000005];

bool visited[2000005];

int bfs(int start_id){
	long long min_num = 0;
	std::queue<long long> b;
	b.push_back(x[start_id]);
	visited[x[start_id]] = true;
	for(int i = start_id + 1;i <= n;++i){
		if(visited[x[i]])
			continue;
		b.push_back(x[i]);
		
	}
	return 
}

int main() {
	std::cin >> c >> t;
	while(t--) {
		std::cin >> n >> d;
		for(int i = 1; i <= n; i++)
			std::cin >> x[i];
		std::cout << bfs() << '\n';
	}
	return 0;
}
