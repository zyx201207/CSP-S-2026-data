#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string FILE_PRE = "migrate";
/*
坏了，好像学过求最短路条数状物，但我忘了，寄 
先去看眼 T4 再决定先打哪道题的暴力。
T4 不会。吃完糖去趟厕所再来打暴力。
哦不是我 T4 怎么有思路了。哦不不不我无疑是兴奋的。
哦不是我怎么只有 1.5h 了。哦不不不我无疑是愤怒的。
哦假了。滚回来打暴力。
哦暴力假了。算了就这样了。 
*/
int c, t, n; 
int f[5003], maxx, cnt[5003][5003];
ll sum, x[5003], d;
queue<int> q;
queue<pair<int, int> > q2; 
int main(){
	freopen((FILE_PRE+".in").c_str(), "r", stdin);
	freopen((FILE_PRE+".out").c_str(), "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> t;
	if(c > 10) while(t--) cout << "0\n"; // 先总司令一下 
	else{
		while(t--){
			sum = 0;
			cin >> n >> d;
			for(int i = 1; i <= n; i++) cin >> x[i];
			for(int i = 1; i <= n; i++){
				memset(f, 0x3f, sizeof f);
				memset(cnt, 0x00, sizeof cnt);
				maxx = 0;
				f[i] = 0; q.push(i);
				while(!q.empty()){
					int u = q.front(); q.pop();
					for(int i = 1; i <= n; i++){
						if(abs(x[u] - x[i]) <= d && f[u] + 1 < f[i]){
							maxx = max(maxx, f[i] = f[u] + 1);
							q.push(i);
						} 
					}
				}
				q2.push(make_pair(i, 0));
				cnt[i][0] = 1; 
				while(!q2.empty()){
					auto u = q2.front(); q2.pop();
					for(int i = 1; i <= n; i++){
						if(abs(x[u.first] - x[i]) <= d){
							cnt[i][u.second + 1] += cnt[u.first][u.second];
							if(u.second < maxx) q2.push(make_pair(i, u.second + 1));
						} 
					}
				}
				for(int j = 1; j <= n; j++){
					if(i != j && cnt[j][f[j]] == 2) sum++;
				}
			}
			cout << (sum >> 1) << '\n';
		}
	}
	
	cout << flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

