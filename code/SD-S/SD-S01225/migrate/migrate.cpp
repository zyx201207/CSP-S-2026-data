#include <algorithm>
#include <cstdint>
#include <fstream>

int main() {
	using namespace std;
	ifstream cin("migrate.in");
	ofstream cout("migrate.out");
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n;
		int64_t dmax;
		cin >> n >> dmax;
		auto pos = new int64_t[n];
		for(int i = 0; i < n; i++)
			cin >> pos[i];
		
		if(!c|| 11 <= c && c <= 12)
		{
			if(n == 1)
				cout << 0 << '\n';
			else 
			{
				auto d = pos[1] - pos[0], part = dmax / d;
				if(part < 2)
					cout << "0\n";
				else
					cout << n - part << "\n";
			}
			delete[] pos;
			continue;
		}
		int64_t ans = 0;
		for(int left = 0; left < n; left++)
		{
			vector<pair<int, int>> paths;
			paths.emplace_back(0, 1); 
			int sum = 1, windowl = left, windowr = left;
			for(int right = left + 1; right < n; right++)
			{
				while(windowl < right && pos[right] - pos[windowl] > dmax)
				{
					sum -= paths[windowl - left].second;
					++windowl; 
				}
				if(windowl == right)
					break;
				while(windowr < right - 1 &&
					 paths[windowl - left].first == paths[windowr + 1 - left].first)
				{
					++windowr;
					sum += paths[windowr - left].second;
				}
				paths.emplace_back(paths[windowl - left].first + 1, sum);
				if(sum == 2)
					++ans;
			}		
		}
		cout << ans << endl;
		delete[] pos;
	}
	return 0;
}
