#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 500010,M = 300010;
ll n,m,a[N],ans[M];
ll sta[N],top;
bool flag[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(ll i = 1 ; i <= n ; i++){
		for(ll i = 1 ; i <= m ; i++) flag[i] = 0;
		top = 0;
		for(ll j = i ; j <= n ; j++){
			if(flag[a[j]]){
				while(flag[a[j]]){
					flag[a[sta[top]]] = 0;
					top--;
				}
			}
			sta[++top] = j;
			flag[a[j]] = 1;
		}
		for(ll i = 1 ; i <= m ; i++){
			ans[i] += flag[i];
		}
	}
	for(ll i = 1 ; i <= m ; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
/*
题看错了正解没写出来TvT
*/