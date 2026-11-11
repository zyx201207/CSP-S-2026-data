//多测要清空，审题要认真，认真检查对拍，防止变量重名 ，及时保存代码及副本 
//yyc,ytz,lcl,lyh,mpy,ljh,sxz,sbh,bjh,xjy,cjr,emmm,7/3大神保佑
//注意freopen，检查题目名，仔细核对思路，不要着急，一定行
//20min读题 , T1 15min想40min写+调 , T2 25min想45min写+调 , T3 15min想20min写暴力+调试 , T4 15min想20min写暴力+调试
//240-60-75-40-40=25min ， 留至少10分钟检查校对 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5 + 5;
ll n , d;
ll x[N];
ll vis[N];
ll di[N];
pair<ll,ll> mp[N];
vector<ll> vec[N];
bool check(ll st , ll en){
	for(int i = 1 ; i <= n ; i++) vis[i] = 0;
	for(int i = 1 ; i <= n ; i++) di[i] = 1e9;
	queue<pair<ll, ll>> q;// u , dep
	ll midis = 1e9;
	bool flag = 1;
	q.push({st , 0});
	while(!q.empty() && flag){
		ll u = q.front().first;
		ll dis = q.front().second;
		q.pop();
		di[u] = min(di[u] , dis);
		vis[u] = 1;
		for(auto v : vec[u]){
			if(v == en){
				midis = min(midis , dis + 1);
			}
			if(!vis[v]) q.push({v , dis + 1});
		}
	}

	//求距离  
	for(int i = 1 ; i <= n ; i++) vis[i] = 0;
	for(int i = 1 ; i <= n ; i++) mp[i].first = mp[i].second = 1e9;
	queue<array<ll , 4> > b;
	b.push({st , 0 , 0 , -1});
	b.push({en , 0 , 1 , -1});//双向bfs,0为起点开始，1为终点开始 
	ll cnt3 = 0;
	bool ok = 0;
	ll cnt2 = 0;
	vector<ll> c;
	//最小距离为奇数时，在以终点开始的点到这里的距离为midis/2 + 1时break;
	// 最小距离为偶数时，在以起点开始的点到这里的距离为midis/2 + 1时break;
	while(!b.empty() && !ok){
		ll u = b.front()[0];
		ll dis = b.front()[1];
		ll k = b.front()[2];
		ll fa = b.front()[3];
		b.pop();
		if(midis % 2 == 1 && k && dis == midis / 2 + 1){
			//cout << u << ' ' << dis << ' ' << k << ' ' << fa << '\n';
			break;
		} 
		if(midis % 2 == 0 && !k && dis == midis / 2 + 1){
			//cout << u << ' ' << dis << ' ' << k << ' ' << fa << '\n';
			break;
		} 
		if(vis[u] == 0) mp[u].first = k;
		if(vis[u] == 1) mp[u].second = k;
		vis[u]++;
		/*if(u == 2 && st == 1 && en == 4){
			cout << 2 << ' ' << vis[u] << ' ' << k << '\n';
		}
		if(u == 4 && st == 1 && en == 4){
			cout << 3 << ' ' << vis[u] << ' ' << k << '\n';
		}*/
		if(vis[u] == 2 && ((k != mp[u].first)) && mp[u].first != 1e9){
			cnt2++;
			continue;
		}
		if(vis[u] == 3 && ((k != mp[u].first) || (k != mp[u].second)) && mp[u].first != 1e9 && mp[u].second != 1e9){
			cnt3++;
			cnt2--;
			continue;
		}
		if(vis[u] > 3 && ((k != mp[u].first) || (k != mp[u].second)) && mp[u].first != 1e9 && mp[u].second != 1e9){
			//cout << u;
			ok = 1;
		}
		if(vis[u] >= 2){
			//cout << u << ' ';
			continue;
		}
		for(auto v : vec[u]){
			//cout << v << ' ' << dis + 1 << ' ' << di[u] << ' ' << midis << ' '<< k << ' ' << u << 'a' << '\n';
			if(v != fa){
				if(k == 0 && dis + 1 == di[v]){
					//cout << "AA";
					b.push({v, dis + 1 , k , u});
				}
				if(k == 1 && dis + 1 == midis - di[v]){
					//cout << "BB";
					b.push({v, dis + 1 , k , u});
				}
			}
		}
	}
	//if(st == 1 && en == 4) cout << midis << ' ' << cnt2 << ' ' << cnt3 << '\n';
	if(!ok && cnt2 + cnt3 == 2){
		//cout << midis << ' ';
		//cout << st << ' ' << en << '\n';
		return true;
	} 
	else return false;
}
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c , t;
	cin >> c >> t;
	while(t--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++){
			if(!vec[i].empty()) vec[i].clear();
		}
		if(c == 11 || c == 12){
			int a , b;
			cin >> a >> b;
			int dif = abs(a - b);
			for(int i = 3 ; i <= n ; i++){
				cin >> a;
			}
			if(dif * 2 <= d && d < dif * 3){
				cout << n - 3 << '\n';
			}else{
				cout << 0 << '\n';
			}
		}
		for(int i = 1 ; i <= n ; i++){
			cin >> x[i];
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(i == j) continue;
				if(abs(x[i] - x[j]) <= d) vec[i].push_back(j);
			}
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				ans += check(i , j);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2 
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
