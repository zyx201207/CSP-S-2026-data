#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;//cnt建了的边数 
int la[300005];//每个数上一次出现的位置 
struct node{
	int l, r, p;//p是否失效 
//	bool opreator < (*const node k) const{
//		return k.l > l;
//	}
}a[500005];
//priority_queue <node> q;
int ans[300005];
vector <pair<int, int>> v;
int c[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
		la[i] = -1;
	for (int i = 1;i <= n;i++){
		cin >> c[i];
		if(la[c[i]] != -1)
			//q.push({la[x], i, 0});
			a[++cnt].l = la[c[i]], a[cnt].r = i, a[cnt].p = 0;
		la[c[i]] = i;
	} 
//	for(int i = 1;i <= cnt;i++)
//		cout << a[i].l << " " << a[i].r << '\n';
	for(int i = 1;i <= n;i++){//枚举每一局游戏 
		for(int j = 1;j <= cnt;j++){
			if(a[j].l < i)
				a[j].p = 1;
		}
		int lst = i;
		while(v.size())
			v.clear();
		for(int j = 1;j <= cnt;j++){
			if(a[j].p == 0 && a[j].l >= lst){
				v.push_back({lst, a[j].l - 1});
				lst = a[j].r;
			}
		}
		v.push_back({lst, n});
		for(int j = 0;j < v.size();j++){
			//cout << v[j].first << " " <<  v[j].second << '\n';
			for(int k = v[j].first;k <= v[j].second;k++){
				ans[c[k]] += 1;
			}
		}
	}
	cout << '\n';
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
