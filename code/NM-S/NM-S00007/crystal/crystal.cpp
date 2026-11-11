#include<bits/stdc++.h>
#define ll long long
//#define pii pair<ll,ll>
using namespace std;
const int maxn = 5e5+10;
ll n,m,ans,tot=1,cn,lst=-1;
ll a[maxn],pos[maxn];
//pair<ll,ll> d[maxn];
pair<ll,ll> v[maxn];
map<ll,int> mp;
/*ll check(ll x){
	ll ans1 = 0;
	ll mm = m;
	for (int i=1;i<=n;i++){
		b[i] = x-a[i];
	}
	sort(b+1,b+1+n);
	int pos = 1;
	while (b[pos]<0) pos++;
	while (m>0){
		if (pos>n) break;
		if (mm>=b[pos]){
			mm -= b[pos];
			ans1 ++ ;
		}
		else break;
	}
	return ans1;
}*/
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	//if (a.first == b.first){
	//	return a.second<b.second;
	//}
	return a.second<b.second;
}
void solve(){
	ll anss = 0;
	for (int i=1;i<=n;i++){
		ans = 0;
		ans += mp[a[i]];
		ll mm = m;
		for (int j=i-1;j>=1;j--){
			if (a[i] == a[j]) continue;
			if (mm>=(a[i]-a[j])){
				mm -= a[i]-a[j];
				ans ++;
				//cout<<mm<<"\n";
			}
		}
		anss = max(anss,ans);
	}
	cout<<anss<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	stable_sort(a+1,a+1+n);
	if (n<=10000){
		solve();
		return 0;
	}
	for (int i=1;i<=n;i++){
		ll t = a[i]-a[i-1];
		if (t>0) {
			v[tot++] = {t,a[i]};
			//pos[d[i]] = a[i];
		}
	}
	stable_sort(v+1,v+tot,cmp);
	//cn = mp[v[1].second-v[1].first];
	if (m>=v[1].first*mp[v[1].second-v[1].first]){
		m -= v[1].first*mp[v[1].second-v[1].first];	
		cn += mp[v[1].second-v[1].first];
		lst = v[1].second;
	}	
	for (int i=2;i<tot;i++){
		if (m>=(cn+mp[v[i].second-v[i].first])*v[i].first){
			m -= (cn+mp[v[i].second-v[i].first])*v[i].first; 
			cn +=  mp[v[i].second-v[i].first];
			lst = v[i].second; 
		}
		else {
			break;
		}
	}
	cn += mp[lst];
	cout<<cn<<"\n";
	return 0;
} 
