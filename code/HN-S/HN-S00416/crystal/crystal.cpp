#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N];
int n;
ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,less<int>());
	int ans = 0;
	int last_id = 2;
	int last_cnt = 1;
	ll last_k = m;
	for(int i = 1;i<=n;i++){
		ll k;
		int id,cnt;
		if(i==1){
			k = last_k;
			id = last_id;
			cnt = last_cnt;
		}else{
			k = last_k+(a[last_id-1]-a[i-1]);
			id = last_id;
			cnt = last_cnt-1;
		}
		while(id<=n){
			ll d = (a[id]-a[id-1])*(id-i);
			if(k-d>=0){
				k-=d;
				cnt++;
			}else{
				break;
			}
			id++;
		}
		ans = max(ans,cnt);
		last_id = id,last_cnt = cnt,last_k = k;
	}
	cout<<ans;
	return 0;
}
