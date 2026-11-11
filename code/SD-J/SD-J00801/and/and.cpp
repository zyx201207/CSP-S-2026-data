#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
#define first x
#define second y
const int N = 2e5 + 10;
int n,m,a[N],ans = -1,vis[50];
pair <int,int> st[50];
vector <int> f[50];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = n;i >= 1;i--){
		if(__lg(a[i]) == __lg(a[i - 1])) f[__lg(a[i])].push_back(a[i]);
		else f[__lg(a[i])].push_back(a[i]);
	}
	int ant = 0;
	for(int i = 31;i >= 1;i--){
		if(f[i].empty()) continue;
		if(f[i].size() < m){
			for(int j = 0;j < f[i].size();j++){
				f[i][j] = f[i][j] & ((1 << i) - 1);
				f[__lg(f[i][j])].push_back(f[i][j]);
			}
		}else{
			ant = i;
			break;
		}
	}
	vector <int> g = f[ant];
//	cout << g.size() - m<< "  ";
	int pc = g.size() - m;
	if(pc == 0){
		for(auto x : g){
			if(x != -1){
				if(ans == -1) ans = x;
				else ans &= x;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = ant;i >= 1;i--){
		int ys = 0,np = 0;
		for(auto x : g){
			if(x == -1) continue;
			if(x & (1 << (i - 1))){
				np = 1;
				break;
			} 
		}
		if(!np) continue;
		for(int j = 0;j < g.size();j++){
			if(g[j] & (1 << (i-1))) ys++;
			else{ 
				pc--;
				g[j] = -1;
				if(pc == 0){
					for(auto x : g){
						if(x != -1){
							if(ans == -1) ans = x;
							else ans &= x;
//							cout << ans << "\n";
						}
					}
					cout << ans;
					return 0;	
				}
			}
		}
	}
	if(pc > 0){
		for(auto x : g){
			if(x != -1){
				if(ans == -1) ans = x;
				else ans &= x;
				m--;
				if(m == 0){
					cout << ans;
					return 0;
				}
			}
		}
	}
	return 0;
} 
