#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <windows.h>
using namespace std;

int main() {
	int n, m;
	int r, fr;
	cin >> n >> m;
	int num[n];
	int gg[m] = {0};
	bool visited[m][n] = {0};
	stack<int> wei;
	stack<int> shu;
	fr = 0;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < m;) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				gg[i] = num[j];
				visited[i][j] = 1;
				//wei.push(i);
				//shu.push(j);
				break;
			}
		}
		for (int j = 0; j < m; j++)
			cout << gg[j] << " ";
		cout << endl;
		Sleep(1000);
		if (gg[i] == 0) {
			if (i == 0)
				break;
			else {
				for (int k = 0; k < n; k++)
					visited[i][k] = 0;
				i -= 2;
				gg[i + 1] = 0;
				//wei.pop();
				//shu.pop();
			}
		}
		if (i == m - 1) {
			r = gg[0];
			for (int j = 1; j < m; j++) {
				r = r & gg[j];
			}
			if (r > fr)
				fr = r;
			cout << fr << endl;
			gg[i] = 0;
			i--;
			//wei.pop();
			//shu.pop();
		}
		i++;
	}
	cout << fr;
	return 0;
}