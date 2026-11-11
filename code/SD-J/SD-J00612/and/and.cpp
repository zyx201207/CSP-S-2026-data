#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int maxn=36,maxnm=2e5+5;
ll n,m;
vector<ll>lg[maxn];
ll a[maxnm];
ll f[maxnm];
void ten_to_two(ll x,ll ii){
	ll cnt=0;
	while(x!=1){
		cnt++;
		if(x%2==1){
			lg[cnt].push_back(ii);
		}
		x/=2;
	}
	lg[++cnt].push_back(ii);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		ten_to_two(a[i],i);
	}
	ll cnt=0;
	for(ll i=31;i>=1;i--){
		if(int(lg[i].size())>=m){
			for(ll ou:lg[i]){
				f[++cnt]=a[ou];
			}
			break;
		}
	}
	sort(f+1,f+cnt+1);
	ll res=f[cnt];
	for(ll i=cnt-1;i>=cnt-m+1;i--){
		res&=f[i];
	}
	cout<<res;
	return 0;
}
