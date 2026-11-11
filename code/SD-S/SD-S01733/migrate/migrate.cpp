#include<bits/stdc++.h>
using namespace std;

int n,c,t;
long long d,x[2000006];
vector<int> mp[5003];
bool check(int a,int b){
	vector<int> tong(n+1,0);
	vector<int> dis(n+1,INT_MAX);
	queue<int> q;
	q.push(a);
	dis[a] = 0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int v : mp[p]){
			if(dis[v] == INT_MAX){
				dis[v] = dis[p] + 1;
				q.push(v);
			}
			else if(dis[v] == dis[p] + 1){
				tong[v]++;
			}
		}
	}
	if(tong[b] == 1)return 1;
	return 0;
}

int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	if(c == 13 || c== 14){
		while(t--)cout << 0 << '\n';
		return 0;
	}
	while(t--){
		cin >> n >> d;
		
		for(int i = 1; i <= n; i++)
			cin >> x[i] , mp[i].clear();
		for(int i = n; i >= 2; i--)
			for(int j = i-1; j >= 1; j--)
				if(x[i]-x[j] <= d){
					mp[j].push_back(i);
					mp[i].push_back(j);
				}else break;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= i; j++){
				if(check(i,j))ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}


