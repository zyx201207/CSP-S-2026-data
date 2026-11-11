#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;
struct node{
	ll num,id;
	bool operator <(const node &w)const{
		return num > w.num;
	}
} cnt[N];
ll n,m,a[N],nid,ans;
unordered_map<ll,ll> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(!mp.count(a[i])) nid++, mp.insert({a[i],nid});
		cnt[mp[a[i]]].num++;
		cnt[mp[a[i]]].id = i;
	}
	ll maxn = 1;
	for(ll i = 1; i <= n; i++){
		if(cnt[mp[a[maxn]]].num < cnt[mp[a[i]]].num){
			maxn = cnt[mp[a[i]]].id;
		}
	}
	sort(a+1,a+1+n);
//	for(ll i = 1 ;i <= n; i++) cout << a[i] << ' ';
//	cout << '\n';
	ll res = -1;
	for(ll k = 1; k <= n; k++){
		if(cnt[mp[a[k]]].num == cnt[mp[a[maxn]]].num){
			ll pos = lower_bound(a+1,a+1+n,k) - (a+1) + 1;
			ll flag = false;
		//	cout << a[pos] << '\n';
			ans = 0;
			for(ll i = pos; i >= 1; i--){
		//		cout << pos << ":" << a[pos] << '\n';
				if(a[i] > a[pos]) continue;
				m -= (a[pos] - a[i]);
				if(m >= 0){
		//			cout << m << " " << (a[pos] - a[i]) << '\n';
					ans++;
					a[i] = a[pos];
					if(i == 1) flag = true, ans += cnt[mp[a[k]]].num; 
				}
				else{
					res = max(res, ans + cnt[mp[a[k]]].num);
					break;
				}
			}
			while(flag == true){
				ans = cnt[mp[a[pos]]].num;
				flag = false;
				pos = lower_bound(a+1,a+1+n,a[pos]+1) - (a+1) + 1;
		//		cout << pos << ":" << a[pos] << '\n';
				for(ll i = pos; i >= 1; i--){
					if(a[i] > a[pos]) continue;
					m -= (a[pos] - a[i]);
					if(m >= 0){
		//				cout << m << " " << (a[pos] - a[i]) << '\n';
						ans++;
						a[i] = a[pos];
						if(i == 1) flag = true, ans += cnt[mp[a[pos]]].num; 
					}
					else{
						res = max(res, ans + cnt[mp[a[pos]]].num);
						break;
					}
				}
			}  
		}
	}
	cout << res << '\n';
	return 0;
} 
