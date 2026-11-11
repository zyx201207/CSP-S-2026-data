#include<bits/stdc++.h>
#define ll long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
#define pii pair<int,int>
#define pic pair<int,char>
#define pll pair<ll,ll>
using namespace std;
const int N = 5e5 + 10;
ll ans[N];
vector<int> wei[N];
bool jia[N];
void solve(){
	int n,m;
	cin >> n >> m;
	vector<ll> v(n + 2);
	int mj;
	for(int i = 1;i <= n;i ++){
		cin >> mj;
		v[i] = mj;
		wei[mj].push_back(i);
	}
	for(int i = 1;i <= n;i ++){
		int k = i;
		for(int j = 1;j <= m;j ++){
			jia[j] = 0;
		}
		while(k <= n){
			if(wei[v[k]].back() != k){
				k = wei[v[k]].back();
				jia[v[k]]  = 1;
			}else{
				jia[v[k ++]] = 1;
			}
		}
		for(int j = 1;j <= m;j ++){
			ans[j] += jia[j];
		}
		cout << endl;
	}
	for(int i = 1;i <= m;i ++){
		cout << ans[i] << ' ';
	}
	return; 
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fast;
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
	return 0;
}
//ciolo~
//根本就没有这样的题目！
//你只是怕了
//完全看不出用什么算法
//dp要d神马，搜索要搜神马，图论就更别提了
//依旧神秘
//依旧依旧 
