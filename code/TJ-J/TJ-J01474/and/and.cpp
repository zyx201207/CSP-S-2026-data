#include <bits/stdc++.h> 
using namespace std;

int n,m;
int a[200010];
int b[20010][20010];
vector<int> ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i <= n-m; i++){
		for(int j = i; j < m; j++) b[i][j] = a[j];
	}
	for(int i = 0; i <= n-m; i++){
		int x = b[i][0];
		for(int  j = 1; j < m; j++){
			x &= b[i][j]; 
		}
		ans.push_back(x);
	}
	int maxx = INT_MIN;
	for(int i = 0; i < (int)ans.size(); i++){
		maxx = max(maxx,a[i]);
	}
	cout << maxx;
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
