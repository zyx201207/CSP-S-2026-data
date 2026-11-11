#include<bits/stdc++.h>
using namespace std;
#define ull long long
#define int long long

int c,t;
int minn;
int record;
ull n;
ull d;
ull x[2000010];
/*
void dfs(int current, int end, int step){
	if(current == end){
		if(minn == step){
			record++;
		}
	}
	if(step > minn){
		return;
	}
	int s = 1;
	while(a[current] + d >= a[s]){
		dfs(current+s, end, step+1);
		s++;
	}
}*/

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while(t > 0){
		t--;
		
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		
		if(c == 11 || c == 12){
			ull da = x[2]-x[1];
			ull result = 0;
			for(ull i = 1; i <= n; i++){
				long long te = ((x[n]-x[i])/d + d/da);
				if(te > 0){
					result += ((n-i)+1)-te;
				}
			}
			cout << result << '\n';
		}
	}
    
    return 0;
}
