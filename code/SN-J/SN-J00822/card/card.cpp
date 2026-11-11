// 张睿航 SN-J00822 西安市第六中学 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
int zhn, zhm;
int zha[100005];
int zhlast[100005];
ll zhcnt[100005];
int zhsum[20005][3005];
vector<int> stk;

int main() {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	bool A = 1; 
	cin >> zhn >> zhm;
	for(int i = 1; i <= zhn; i ++) {
		cin >> zha[i];
		if(i != 1 && zha[i] < zha[i - 1]) A = 0;
	}
	if(A) {
		for(int i = 1; i <= zhn; i ++) {
			zhcnt[zha[i]] += i;
			if(zha[i - 1] == zha[i]) {
				zhcnt[zha[i]] -= i - 1;
			}
		}
		for(int i = 1; i <= zhm; i ++) {
			cout << zhcnt[i] << ' ';
		}
		return 0;
	}
	for(int i = zhn; i > 0; i--) {
		if(zhlast[zha[i]] == 0) {
			zhlast[zha[i]] = i;
			for(int j = 1; j <= zhm; j ++) {
				zhsum[j][i] = zhsum[j][i + 1];
				zhcnt[j] += (ll)zhsum[j][i];
			}
			zhsum[zha[i]][i] ++;
			zhcnt[zha[i]] ++;
		}
		else {
			for(int j = 1; j <= zhm; j ++) {
				zhsum[j][i] = zhsum[j][zhlast[zha[i]]];
				zhcnt[j] += (ll)zhsum[j][i];
			}
		}
	}
	for(int i = 1; i <= zhm; i ++) {
		cout << zhcnt[i] << ' ';
	}
	return 0;
} /*
4 3
1 2 1 3
*/
