#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N = 1e5 + 10;
int n, L[N], suf[N], pre[N]; 
// suf[i]表示最后一个包含i的，pre[i]表示最先一个包含i的 
ll x[N], d; int ansu[N][2], ansv[N]; // 0:没有+1路径 
int vl[N], vr[N]; 

void solve() {
	
	cin >> n >> d; 
	for(int i=1;i<=n;i++) {
		cin >> x[i]; 
		int pos = lower_bound(x+1, x+i, x[i]-d) - x; 
		if(pos > i-1) L[i] = i; 
		else L[i] = pos; 
		vl[L[i]] = (vl[L[i]]==0?i:min(vl[L[i]],i)), 
		vr[L[i]] = max(vr[L[i]],i); 
		suf[L[i-1]] += i-1, suf[L[i]] -= i-1; 
	} suf[L[n]] += n; suf[n+1] -= n; L[n+1] = n+1;  
	for(int i=1;i<=n;i++) suf[i] += suf[i-1]; 
	for(int i=1;i<=n;i++) pre[i] = i; 
	
	for(int u=1;u<=n;u++) { 
		if(u == L[suf[u]]) { //u可以在1~suf[u]机动 
			for(int lst=L[u];lst<=L[u+1]-1;lst++) {
				ansu[u][0] += ansu[lst][0] + ansu[lst][1]; 
				ansu[u][1] += ansu[lst][1]; 
			} ansu[u][0] ++;
		} else if(u == L[suf[u]] + 1) {                                                                                                                                                                                    
			for(int lst=L[u];lst<=L[u+1]-1;lst++) {
				ansu[u][1] += ansu[lst][0]; 
			} ansu[u][1]++;
		}cout<<ansu[u][0]<<' '<<ansu[u][1]<<endl;
	} for(int v=n;v>=1;v--) {
		
		for(int lst=vl[v];lst<=vr[v];lst++) {
			ansv[v] += ansv[lst]; 
		} ansv[v] ++; 
	}
	
	ll tot = 0; 
	for(int i=1;i<=n;i++) {//u>=i  v<=i 
		tot+=ansv[i]*ansu[i][1]-1;
	}
	
	cout << tot <<endl; 
	
}

signed main() {

  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);

  int _; cin >> _; while(_--)
	solve();
	
	return 0;
	
}

