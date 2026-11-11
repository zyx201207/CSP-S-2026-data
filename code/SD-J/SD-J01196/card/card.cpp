#include <bits/stdc++.h>
using namespace std;

const int M = 5e5;
int a[M + 5];

map <int, long long> ans;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		vector <int> in;
		vector <bool> ddd(M + 5);
		in.clear();
		for(int j = 1;j <= m;j++) ddd[j] = false;
		for(int j = i;j <= n;j++){
			if(ddd[a[j]] == true){
				while(in.size() > 0){
					if(in.size() == 0) break;
					if(in[in.size() - 1] != a[j]) in.pop_back();
					else{
						in.pop_back();
						break;
					}
//					cout << "break:" << in[in.size() - 1] << endl;
				}
//				in.push_back(a[j]);
			}
			else{
				ddd[a[j]] = true;
			}
			in.push_back(a[j]);
		}
		while(in.size() > 0){
			ans[in[in.size() - 1]]++;
//			cout << in[in.size() - 1] << " ";
			in.pop_back();
		}
//			cout << endl;
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
