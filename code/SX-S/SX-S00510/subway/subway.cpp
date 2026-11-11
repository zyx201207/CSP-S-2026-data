#include <bits/stdc++.h>
using namespace std;

struct line {
	vector<int> index;
	vector<int> pay;
};
line a[500000];
int start,end;
void pp(int start){
	
}
int main() {
	freopen("subway.in",r,stdin);
	freopen("subway.out",w,stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int r[500000];
	for (int i = 0; i < m; i++) {
		cin >> r[i];
	}
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		int num, l, num2, l2;
		cin >> num >> l;
		for (int j = 1; j < y; j++) {
			int num1, l1;
			cin >> num1 >> l1;
			a[num1].index.push_back(num2);
			a[num1].pay.push_back(l2);
			l2 = l1;
			num2 = num1;
		}
		a[num2].index.push_back(num);
		a[num2].pay.push_back(l);
	}
	while(q--){
		cin>>start>>end;
		pp(start);
		cout<<start+end+12;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
