#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
const long long inf = 9E18;
int c , n , m , D , q , w[500001] , k , a , t , x , y , cnt;
vector <pair <int , long long>> edges[500501];
long long d[500501] , ans[100001];
vector <int> tst[500501];
map <pair <int , int> , vector <int>> mp;
map <pair <int , int> , bool> vis;
long long read(){
	char c;
	for (c = getchar() ; c < '0' || c > '9' ; c = getchar());
	long long res = 0;
	for (; c >= '0' && c <= '9' ; c = getchar())
		res = res * 10 + c - '0';
	return res;
}
void write(const long long &x){
	if (x <= 9)
		putchar(x + '0');
	else{
		write(x / 10);
		putchar(x % 10 + '0'); 
	}
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout); 
	c = read();
	n = read();
	m = read();
	D = read();
	q = read(); 
	for (int i = 1 ; i <= m ; i++)
		w[i] = read();
	for (int i = 1 ; i <= n ; i++){
		k = read();
		for (int j = 1 ; j <= k ; j++){
			a = read();
			t = read();
			edges[m + i].push_back({a , t});
			edges[a].push_back({m + i , t});
		}
	}
	for (int i = 1 ; i <= q ; i++){
		x = read();
		y = read();
		tst[x].push_back(y);
		mp[{x , y}].push_back(i);
		vis[{x , y}] = 1;
	}
	for (int i = 1 ; i <= m ; i++)
		if (tst[i].size()){
			priority_queue <pair <long long , int> , vector <pair <long long , int>> , greater <pair <long long , int>>> pq;
			for (int j = 1 ; j <= n + m ; j++)
				d[j] = inf;
			cnt = tst[i].size();
			d[i] = 0;
			pq.push({0 , i});
			while (pq.size()){
				if (pq.top().first != d[pq.top().second]){
					pq.pop();
					continue;
				}
				x = pq.top().second;
				pq.pop();
				if (vis.find({i , x}) != vis.end())
					if (!--cnt)
						break;
				for (auto i : edges[x])
					if (d[i.first] > d[x] + i.second){
						d[i.first] = d[x] + i.second;
						pq.push({d[i.first] , i.first});
					}
			}
			for (auto j : tst[i])
				for (auto k : mp[{i , j}])
					ans[k] = d[j] + w[i] + w[j];
		}
	for (int i = 1 ; i <= q ; i++){
		write(ans[i]);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
