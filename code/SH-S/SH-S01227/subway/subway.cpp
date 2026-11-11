#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,c,q,d;
struct nd{
	int time2;//Õ¾ÄÚºÍÕ¾Íâ 
	LL hasrw[505];
} city[20004];
struct rail{
	int nb;
	bool sta[20004];
} rw[505];
LL flag[500005];
LL ans;
int main(){
	freopen("E:\\NOI\\subway.in","r",stdin);
	freopen("E:\\NOI\\subway.out","w",stdout);
	cin >> c >> n >>m >> d >> q;
	for(int i =1; i <= m; i++){
		int x;
		cin >> x;
		city[i].time2 = x;
	}
	for(int i = 1; i <= n; i++){
		int z;
		cin >> z;
		while(z--){
			int x, y;
			cin >> x >> y;
			city[x].hasrw[i] = y;
			rw[i].sta[x] = true;
		}
	}
	queue<int>que;
	while(q--){
		int st, ed;
		cin >> st >> ed;
		memset(flag,0x3f,sizeof(flag));
		que.push(st);
		flag[st]=0;
		while(!que.empty()){
			nd cur = city[que.front()];
			for(int i = 1; i <= n; i++){
				if(cur.hasrw[i]){
					for(int j = 1; j <= m; j++){
						if(rw[i].sta[j] && flag[j]>flag[que.front()]+cur.hasrw[i]+city[j].hasrw[i]){
							que.push(j);
							flag[j] = flag[que.front()]+cur.hasrw[i]+city[j].hasrw[i];
						}
					}
				}
			}
			que.pop();
		}
		cout << flag[ed]+city[st].time2 + city[ed].time2 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
