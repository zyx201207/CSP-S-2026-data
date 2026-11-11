#include<bits/stdc++.h>
using namespace std;
int n,m,p = 1,maxn = -1e9,a[200005];
bool f = 1,ff = 1,k[200005];
map<int,bool> s;
void dfs(int s,int l,int p){
	if(s == m + 1){
		maxn = max(maxn,p);
		return ;
	}
	for(int i = l;i <= n - m + s + 1;i++){
		if(k[i]) continue;
		k[i] = 1;
		if(s == 0){
			dfs(s + 1,i + 1,a[i]);
		}else{
			dfs(s + 1,i + 1,a[i] & p);
		}
		k[i] = 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	s[p] = 1;
	for(int i = 1;i <= 30;i++){
		p *= 2;
		s[p] = 1;
	}
	if(s[n] == 0) ff = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
		if(s[a[i] + 1] == 0) f = 0;
		if(a[i] + 1 != i) ff = 0;
	}
	if(f){
		cout << maxn;
	}else if(ff){
		if(m % 2){
			cout << maxn;
		}else{
			int p = 1;
			for(int i = 1;i <= m / 2;i++){
				maxn -= p;
				p *= 2;
			}
			cout << maxn;
		}
	}else{
		maxn = 0;
		dfs(0,1,0);
		cout << maxn;
	}
	return 0;
}
