#include <algorithm>
#include <cstdint>
#include <fstream>

int main() {
	using namespace std;
	ifstream cin("crystal.in");
	ofstream cout("crystal.out");
	int n;
	int64_t opmax;
	cin >> n >> opmax;
	auto val = new int64_t[n];
	for(int i = 0; i < n; i++)
		cin >> val[i];
	sort(val, val + n);
	
	int64_t opsum = 0;
	int ans = 1;
	for(int right{1}, left{}; right < n; right++)
	{
		opsum += (val[right] - val[right - 1]) * (right - left);
		while(opsum > opmax)
		{
			opsum -= val[right] - val[left];
			++left; 
		}
		ans = max(ans, right - left + 1);
	}
	cout << ans << endl;
	delete[] val; 
	return 0;
}
