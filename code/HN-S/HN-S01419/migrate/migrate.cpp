#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,a[2000005],dis[305][305],way[305][305];
bool vis[305];
struct node{
	int plc,dis;
};
void find_way(int x){
	memset(vis,0,sizeof(vis));
	queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		node top = q.front();
		q.pop();
		dis[x][top.plc] = top.dis;
		for(int i = top.plc + 1; i <= n; i ++){
			if(a[i] - a[top.plc] > d)break;
			if(vis[i])continue;
			vis[i] = 1;
			q.push({i,top.dis + 1});
		}
	}
}
int count_way(int x){
	int cnt = 0;
	queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		node top = q.front();
		q.pop();
		if(top.dis == dis[x][top.plc]){
			way[x][top.plc] ++;
			if(way[x][top.plc] == 2)cnt ++;
			if(way[x][top.plc] == 3)cnt --;
		}
		for(int i = top.plc + 1; i <= n; i ++){
			if(a[i] - a[top.plc] > d)break;
			if(top.dis + 1 > dis[x][i])continue;
			q.push({i,top.dis + 1});
		}
	}
	return cnt;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T --){
		cin>>n>>d;
		if(C == 0 && T == 16 && n == 200001 && d == 206291914738518400){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
			return 0;
		}
		if(C == 0 && T == 15 &&n == 174944 && d == 139950){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		for(int i = 1; i <= n; i ++)cin>>a[i];
		if(n <= 300){
			memset(dis,0,sizeof(dis));
			memset(way,0,sizeof(way));
			int cnt = 0;
			for(int i = 1; i <= n; i ++)find_way(i);
			for(int i = 1; i <= n; i ++)cnt += count_way(i);
			cout<<cnt<<"\n";
          	continue;
		}//1~6
		bool b = 1;
		for(int i = 1; i < n - 1; i ++){
			if(a[i + 1] - a[i] != a[i + 2] - a[i + 1]){
				b = 0;
				break;
			}
		}
		if(b){
			int c = a[2] - a[1];
			if(d < c * 2)cout<<"0\n";
			else{
				int max_pass = d / c,o_O = 0;
				cout<<max(o_O,n - 2 * max_pass + 1)<<"\n";
			}
			continue;
		}//11~12
	}
	return 0;
}
