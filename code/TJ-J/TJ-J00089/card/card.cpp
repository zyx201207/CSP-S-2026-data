#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,m,a[500005],cnt[300005],f,maxn,starter;
queue<int> q;
bool check(int x,queue<int> QQ){//检查队列中x是否存在 
	int q1 = 0;
	while(!QQ.empty()){
		q1 = QQ.front();
		if(q1 == x) return true;
		QQ.pop();
	}
	return false;
}
void clear(int x){//清除 
	int q1 = q.front();
	int f = q1;
	while(q1 != x){
		q.pop();
		q.push(q1);
		q1 = q.front();
	}
	//q.pop();
	//q1 = q.front();
	//这个加上的话，不知为何输出飞走了 
	while(q1 != f){
		cnt[q1]--;
		q.pop();
		q1 = q.front();
	}
}
void completely_clear(){//准备下一轮 
	while(!q.empty()){
		int q1 = q.front();
		cnt[q1]++;
		q.pop();
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	starter = 1;
	while(starter <= n){
		for(int i = starter;i <= n;i++){
			f = check(a[i],q);
			if(f){
				clear(a[i]);
			}
			q.push(a[i]);
		}
		completely_clear();
		starter++; 
	}
	for(int i = 1;i <= maxn;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
