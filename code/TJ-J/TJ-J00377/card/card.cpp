#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4 + 10;
int n; string s[N];
ll ans = 0x3f3f3f3f3f3f3f3f;

struct stri{
	ll n; char c;
}v[N];

bool check(){
	for(int l=1, r=n, lidx=0, ridx=s[n].length()-1; l<r||lidx<=ridx; ){
		if(s[l][lidx] != s[r][ridx]){
			return false;
		}
		if(lidx == s[l].length()-1){
			l++;
			lidx = 0;
		}else{
			lidx++;
		}
		if(ridx == 0){
			r--;
			ridx=s[r].length()-1;
		}else{
			ridx--;
		}
	}
	return true;
}

void dfs(ll step){
//	clog << "dfs( step = " << step << ", s = " << s << ")\n";
	if(check()){
		ans = min(ans, step);
		return;
	}
	for(int l=1, r=n, lidx=0, ridx=s[n].length()-1; l<r||lidx<=ridx; ){
		if(s[l][lidx] != s[r][ridx]){
			char c = s[l][lidx];
			s[l][lidx] = s[r][ridx];
			dfs(step+1);
			s[l][lidx];
		}
		
		if(lidx == s[l].length()-1){
			l++;
			lidx = 0;
		}else{
			lidx++;
		}
		if(ridx == 0){
			r--;
			ridx=s[r].length()-1;
		}else{
			ridx--;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	for(int i=1; i<=n; i++){
		cin >> v[i].n >> v[i].c;
		cout <<  v[i].n << v[i].c;
	} 
	
	dfs(0);
	
	cout << ans << "\n";
	return 0;
}
