#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n, m;
char a[500005];
//int vis[300005], ans[300005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		cout << "0 ";
	}
	/*
	for(int i=1;i<=n;i++){
		vector<int> vis(m+5, 0);
		string s = " ";
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				s = s + a[j];
				vis[a[j]] = j;
			} else {
				s = s.substr(0, vis[a[j]]-1);
				s = s + a[j];
				vis.clear();
				for(int z=1;z<=m;z++){
					vis[i] = z; 
				}
			}
		}
		for(int j=1;j<=s.size();j++){
			ans[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	*/
	return 0;
}
