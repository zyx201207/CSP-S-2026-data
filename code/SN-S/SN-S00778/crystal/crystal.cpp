#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5 * 1e5;
const ll maxm = 1e18;
int n,ans = 0;ll m;
struct node{
	ll n;int res;
	node(){	}
	node(ll _n,int _a) : n(_n),res(_a){	}
	bool operator < (const node &o) const{
		return n < o.n;	
	}
};
priority_queue<ll> pq;
node p[maxn+7];
bool IsSpeA = 1,IsSpeB = 1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;ll k;
	
	for(int i=1;i<=n;i++){
		cin >> k;
		if (i!=k) IsSpeA = 0; 
		pq.push(k);
	}
	int num = 0,cnt = 1;
	k = pq.top();
	while(!pq.empty()){
		if(k == pq.top()){
			pq.pop();
			++num;
		}else{
			if(num!=1) IsSpeB = 0;
			p[cnt++] = node(k,num);
			k = pq.top();
			pq.pop();
			num = 1;
			if(pq.empty()) p[cnt] = node(k,1);
		}
	}
	
	if(IsSpeA){
		for(int i=1;i<=cnt-1;++i){
			ll sum = (1+i)*i/2;
			if(sum>m){
				cout << i << endl;
				return 0;
			}
		}
		cout << cnt << endl;
		return 0;
	}else if(IsSpeB){
		ll d = p[2].n - p[1].n;
		for(int i=1;i<=cnt-1;++i){
			ll sum = d*(1+i)*i/2;
			if(sum>m){
				cout << i << endl;
				return 0;
			}
		}
		cout << cnt << endl;
		return 0;
	}
	
	
	for(int i=1;i<=cnt;++i){
		node ii = p[i];
		ll mm = m;
		int tot = p[i].res;
	
		for(int j=i+1;j<=cnt;++j){
			node jj = p[j];
			if(mm < (ii.n) - (jj.n)) break;
			else if(mm >= ((ii.n) - (jj.n))*(jj.res)){
				mm -= ((ii.n) - (jj.n))*(jj.res);
				tot += jj.res;
			}else{
				tot += (mm / (ii.n-jj.n));
				mm -= (ii.n - jj.n) * (mm / (ii.n-jj.n));
			}
		}
		ans = max(ans,tot);
	}
	cout << ans << '\n';
	return 0;
} 

