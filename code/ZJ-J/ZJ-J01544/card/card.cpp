#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n,m;
int a[N];
int nt[N];
int p[M];
int ind[N];
bool vis[N];
int f[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(int i=n;i>=1;i--){
		if(p[a[i]] != 0) nt[i] = p[a[i]];
		else nt[i] = i + 1;
		
		p[a[i]] = i;
		ind[nt[i]]++;
	}
	
	for(int i=1;i<=n;i++){
		if(ind[i] != 0) continue;
		
		int j = i;
		int cnt = 0;
		int last = 0;
		
		while(j <= n){
			if(a[j] != last){
				f[last] += cnt;
				last = a[j];
			}
			
			if(!vis[j]) cnt++;
			vis[j] = true;
			
			j = nt[j];
		}
		
		if(j > n) f[last] += cnt;
	}
	
	for(int i=1;i<=m;i++){
		cout << f[i] << " ";
	}
	
	return 0;
}
