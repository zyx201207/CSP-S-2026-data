#include <bits/stdc++.h>
using namespace std;
int n;long long m;
long long sjs[500005];
bool cmp(long long q,long long h){return q > h;}
long long anss = 0;
priority_queue<long long> que;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> sjs[i];
	sort(sjs+1,sjs+1+n,cmp);
	int l = 1,r = 1;long long cost = 0,len = 1;
	que.push(sjs[l]);
	while(r <= n && l <= r && l <= n){
		if(cost + que.top() - sjs[r+1] <= m){
			//可以入队
			r++;
			len ++;
			que.push(sjs[r]); 
			cost = cost + que.top() - sjs[r];
		}else{
			l++;
			len--;
			long long lastmax = que.top();
			que.pop();
			long long cha = lastmax - que.top();
			cost = cost - que.size() * cha;
		}
		//cout << l << ' ' << r << ' ' << cost << endl;
		anss = max(anss,len);
	}
	cout << anss;
	return 0;
}
