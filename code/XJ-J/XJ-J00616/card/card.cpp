#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5+5;
int n , m , a[N] , val[N] , fa[N] , vis[N] , srt[N] , cnt;
signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = n;i >= 1 && cnt < m;i--){
		if(vis[a[i]] == 0){
			vis[a[i]] = 1;
			fa[a[i]] = a[i + 1];
			srt[++cnt] = a[i];
		}
	}
	for(int i = 1;i <= n;i++){
		val[a[i]]++;
	}
	for(int i = m;i >= 1;i--){
		val[fa[srt[i]]] += val[srt[i]];
	}
	for(int i = 1;i <= m;i++){
		cout<<val[i]<<' ';
	}
}
