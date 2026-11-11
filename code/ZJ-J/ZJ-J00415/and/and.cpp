#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool a[200001][31];
int yuan[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int x,cnt = 31;
		cin >> x;
		yuan[i] = x;
		while(x){
			a[i][--cnt] = (x & 1);
			x >>= 1;
		}
	}for(int i = 1;i <= n;i++){
		for(int j = 0;j < 31;j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	for(int i = 0;i < 31;i++){
		int cnt = 0;
		bool f[200001];
		memset(f,0,sizeof f);
		for(int j = 1;j <= n;j++){
			if(a[j][i]){
				cnt++;
				f[j] = 1;
			}
		}if(cnt >= m){
			int h = i + 1,l = 1;
			while(cnt > m and i != 30){
				while(cnt > m){
					if(not a[l][h])f[l] = 0,cnt--;
					l++;
				}h++;
			}
			int ma = -1;
			for(int j = 1;j <= n;j++){
				if(not f[j])continue;
				if(ma == -1)ma = yuan[j];
				else ma &= yuan[j];
			}cout << ma;
			return 0;
		}
	}cout << 0;
	return 0;
}
