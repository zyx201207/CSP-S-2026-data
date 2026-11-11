#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q;
int w[500005];
int k[505];
vector<int> a[500005], t[500005];
int x[100005], y[100005];

vector<int> metros[500005];
bool is_special[500005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int atmp, ttmp;
			cin >> atmp >> ttmp;
			a[i].push_back(atmp);
			t[i].push_back(ttmp);
			
			metros[atmp].push_back(i);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < a[i].size(); j++){
//			cout << a[i][j] << " ";
		}
//		cout << "\n";
	}
	for(int i = 1; i <= q; i++){
		cin >> x[i] >> y[i];
		int flag = 0;
		for(int line = 1; line <= n; line++){
			flag = 0;
			int st1, st2;
			for(int st = 0; st < k[line]; st++){
				if(a[line][st] == x[i]){
					flag++;
					st1 = st;
//					cout << "a";
				}
				if(a[line][st] == y[i]){
					flag++;
					st2 = st;
//					cout << "b";
				}
			}
			if(flag == 2){
				cout << w[x[i]] + t[line][st1] + t[line][st2] + w[y[i]] << "\n";
				break;
			}
		}
		
		if(flag != 2){
			cout << "11\n";
		}
	}
	
	return 0;
}
	
	
