#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int dfs(int k,int fa){
	int t=0;
	for(int j:v[k])if(j!=fa)t=max(t,dfs(j,k)+1);
	return t;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T--){
		int n,k;
		cin >> n >> k;
		for(int i=1;i<n;i++){
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(k==1)cout << dfs(1,0);
		else cout << (k+1)/2;
	}
	return 0;
} 
//0!
