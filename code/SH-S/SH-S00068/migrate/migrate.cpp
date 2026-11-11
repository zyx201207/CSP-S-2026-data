#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const long long inf = 9E18;
int c , t , n , u , cnt[2000001] , ans;
vector <int> edges[2000001];
queue <int> q;
long long D , d[2000001] , x[2000001];
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout); 
	scanf("%d%d" , &c , &t);
	while (t--){
		ans = 0;
		scanf("%d%lld" , &n , &D);
		for (int i = 1 ; i <= n ; i++){
			scanf("%lld" , &x[i]);
			edges[i].clear();
		}
		for (int i = 1 ; i <= n ; i++)
			for (int j = i + 1 ; j <= n ; j++)
				if (x[j] - x[i] <= D)
					edges[i].push_back(j);
		for (int i = 1 ; i <= n ; i++){
			for (int j = 1 ; j <= n ; j++){
				d[j] = inf;
				cnt[j] = 0;
			}
			d[i] = 0;
			cnt[i] = 1;
			q.push(i);
			while (q.size()){
				u = q.front();
				q.pop();
				for (auto j : edges[u])
					if (d[j] > d[u] + 1){
						d[j] = d[u] + 1;
						cnt[j] = 1;
						q.push(j);
					}else if (d[j] == d[u] + 1)
						cnt[j]++; 
			}
			for (int j = i + 1 ; j <= n ; j++)
				if (cnt[j] == 2)
					ans++;
		}
		printf("%d\n" , ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
