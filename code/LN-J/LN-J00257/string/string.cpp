#include <bits/stdc++.h>
using namespace std;

struct Node {
	int ns;
	int bf;
	char ch;
};

int n, ki, kj;
long long cnt, cont;
vector<Node> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	st.resize(n);
	for(int i=0; i<n; i++){
		cin >> st[i].ns;
		cin >> st[i].ch;
		cont += st[i].ns;
		st[i].bf = (i>0?st[i-1].bf:0) + st[i].ns;
	}
	ki = 0, kj = n-1;
	for(int i=0, j=cont-1; 2*i<cont; i++, j--){
		if(i==st[ki].bf){
			ki++;
		}
		if(j<st[kj-1].bf){
			kj--;
		}
		if(st[ki].ch!=st[kj].ch){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
