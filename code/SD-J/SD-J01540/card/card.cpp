#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
const int M = 300010;
int n, m;
int mr[M], a[N], ans[N];
vector<int> st[N];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = n; i; i --){
		if(!mr[a[i]]){
			mr[a[i]] = i;
			for(auto e : st[mr[a[i + 1]]]){
				st[i].push_back(e);
			    ans[e] ++;
//			    cout << e << ' ';
			}
			st[i].push_back(a[i]);
			ans[a[i]] ++;
//			cout << a[i] << ' ';
		}else{
		    for(auto e : st[mr[a[i]]]){
//				st[i].insert(e);
			    ans[e] ++;
//			    cout << e << ' ';
		    }
		}
//		cout << '\n';
	}
	for(int i = 1; i <= m; i ++){
		cout << ans[i] << ' ';
	}
	return 0;
}




//键盘真难使，tab都用不了，点一个弹俩 
//AK!!!!!!!!!!
//100+100+100+100=400pts!!!!!!!!!!!!!!!
//11:28 edge://surf/启动 !!
