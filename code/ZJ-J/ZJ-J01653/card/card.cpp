#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9;
ll n, m, a[N], tj[N], ans[N], a2[N];
stack <ll> k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll j=1;j<=n;j++){
		memset(tj, 0, sizeof(tj));
		k.push(a[j]);
		tj[a[j]] = 1;
		for(ll i=j+1;i<=n;i++){
			if(tj[a[i]] == 1){
				while(k.top() != a[i]){
					tj[k.top()] = 0;
					k.pop();
				}
				k.pop();
				k.push(a[i]);
			}else{
				k.push(a[i]);
				tj[a[i]] = 1;
			}
		}
		while(!k.empty()){
			ans[k.top()] = 1;
			k.pop();
		}
		for(ll i=1;i<=m;i++){
			a2[i] += ans[i];
			ans[i] = 0;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<a2[i]<<" ";
	}
    return 0;
}