#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 510000;
int a[MAXN],t[MAXN],nxt[MAXN],f[MAXN],sum[MAXN];
bool vis[MAXN];
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		f[a[i]]++;
	}
	for(int i = n ; i >= 1 ; i--){
		if(t[a[i]]==0) nxt[i] = -1;
		else nxt[i] = t[a[i]];
		t[a[i]] = i;
	}
	memset(t,0,sizeof t);
	for(int i = 1 ; i <= n ; i++){
		if(vis[a[i]]==0) sum[i] += f[a[i]];
		vis[a[i]] = 1;
		if(nxt[i]==-1){
			t[a[i]] += sum[i];
			sum[i+1] += sum[i];
		}
		else sum[nxt[i]] += sum[i];
	}
	for(int i = 1 ; i <= m ; i++) cout << t[i] << ' ';
	return 0;
}
//rp++
