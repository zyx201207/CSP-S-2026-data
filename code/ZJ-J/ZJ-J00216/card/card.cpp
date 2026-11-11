#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[300005];
vector<int> v;
int Find(int num){
	for (int i = 0;i < v.size();i++){
		if (v[i] == num){
			return i;
		}
	}return -1;
}int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			if (Find(a[j])!= -1){
				v.erase(v.begin() + Find(a[j]), v.end());
			}v.push_back(a[j]);
		}for (int j : v){
			cnt[j]++;
		}v.clear();
	}for (int i = 1;i <= m;i++){
		cout << cnt[i] <<' ';
	}return 0;
}