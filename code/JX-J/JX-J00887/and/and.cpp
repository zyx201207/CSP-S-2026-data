#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
int a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int n,m;
	cin >> n >> m;
	
	vector<int>b,c;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b.push_back(a[i]);
	}
	
	for(int k = 31;k >= 0;k--){
		for(int g:b){
			if((g>>k)&1){
				c.push_back(g);
			}
		}
		if(c.size() >= m){
			swap(b,c);
		}
		c.clear();
	}
	int ans = b[0];
	for(int g:b){
		//cerr << g << " ";
		ans &= g;
	}
	cout << ans;
	return 0;
}
