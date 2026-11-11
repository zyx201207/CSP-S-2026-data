#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n,m,a[MAXN],ans[MAXN];
bool use[100010],on[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	for(int i = 1;i <= n;++i){
		memset(use,false,sizeof(use));
		memset(on,false,sizeof(on));
		vector<int> q;
		for(int j = i;j <= n;++j){
			if(!on[a[j]]) q.push_back(a[j]),use[a[j]] = true,on[a[j]] = true;
			else while(!q.empty()&&q.back() != a[j]) use[q.back()] = true,on[q.back()] = false,q.pop_back();
		}
		for(int i : q) ++ans[i];
	}
	for(int i = 1;i <= m;++i) cout << ans[i] << " ";
	return 0;
}
/*
4 3
1 2 1 3

3 1 4

10 3
3 1 2 1 3 2 3 1 2 1

10 3 3
*/
