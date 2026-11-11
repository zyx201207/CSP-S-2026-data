#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
int pre[500005];
int nxt[500005];
int ans[500005];
int arr[500005];

set <int> s;

void solve(int x){
	if(x>n){
		return ;
	}
	
	if(s.count(arr[x]) == 0){
		s.insert(arr[x]);
		ans[arr[x]]++;
	}
	
	if(nxt[x] == 0){
		solve(x+1);
	}
	else{
		solve(nxt[x]+1);
	}
}

signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		
		if(!pre[arr[i]]){
			pre[arr[i]] = i;
		}
		else{
			nxt[pre[arr[i]]] = i;
		}
	}
	
	
	for(int i=n; i>=1; i--){
		s.clear();
		solve(i);
	}
	
	
	for(int i=1; i<=m; i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
