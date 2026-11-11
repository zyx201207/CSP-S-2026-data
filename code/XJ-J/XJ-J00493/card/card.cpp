#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5E5 + 10;
int n, m;
int a[N];
map<int,int> mp;
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n ; i++) {
		vector <int> q;
		for(int t = i; t <= n; t++) {
			int pos = -1;
			for(int s = 0; s < q.size() ;s++){
				if(a[t] == q[s]){
					pos = s;
				}
			}
			if(pos == -1){
				q.push_back(a[t]);
			}//找不到
			else{
				for(int j = pos; j < q.size(); j++){
					q[j] = 0;
				}
				q.push_back(a[t]);
			}//找到了 
		}
		for(auto l : q){
			mp[l]++;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cout << mp[i] << " ";
	}
	return 0;
}
