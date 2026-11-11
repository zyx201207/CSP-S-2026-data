#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long read(){long long r = 0,f = 1;char c = getchar();while(c == '-' || (c >= '0' && c <= '9')){if(c == '-'){f = -1;}else{r *= 10;r += int(c - '0');}c = getchar();}while(c >= '0' && c <= '9'){r *= 10;r += int(c - '0');c = getchar();}return r * f;}
int c,n,m,d,q,k,a,t,x,y,too,wdf,stt,anss,lenth1,lenth2;
int w[MAXN];
struct node{
	int l,time;
} st,st1,st2;
struct node1{
	int to,len;
} edge;
bool flag[MAXN];
vector <vector <node> > station(MAXN);
int mp[505][505];
vector <vector <node1> > p(505);
vector <int> start;
vector <int> end;
int ans[505][505];
int check(int abc){
	for(int i = 0;i < end.size();i ++){
		if(abc == end[i]) return true;
	}
	return false;
}
void dfs(int now,int father,int num){
	if(check(now)){
//		ans[stt][now] = min(ans[stt][now],num);
		for(int i = 0;i < station[x].size();i ++){
			if(station[x][i].l == stt){
				lenth1 = station[x][i].time;
				break;
			}
		}
		for(int i = 0;i < station[y].size();i ++){
			if(station[y][i].l == now){
				lenth2 = station[y][i].time;
				break;
			}
		}
		anss = min(anss,num + w[x] + w[y] + lenth1 + lenth2);
		return;
	}
	for(int i = 0;i < p[now].size();i ++){
		if(p[now][i].to == father) continue;
		dfs(p[now][i].to,now,num + p[now][i].len);
	}
}
int main(){
	mp[1][1] = 1;
	memset(mp,0,sizeof(mp));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();n = read();m = read();d = read();q = read();
	for(int i = 1;i <= m;i ++) w[i] = read();
	for(int i = 1;i <= n;i ++){
		k = read();
		for(int j = 1;j <= k;j ++){
			a = read(),t = read();
			st.l = i,st.time = t;
			station[a].push_back(st);
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 0;j < station[i].size();j ++){
			for(int k = j + 1;k < station[i].size();k ++){
				st1 = station[i][j];
				st2 = station[i][k];
				mp[st1.l][st2.l] = (mp[st1.l][st2.l] == 0) ? st1.time + st2.time : min(mp[st1.l][st2.l],st1.time + st2.time);
				mp[st2.l][st1.l] = mp[st1.l][st2.l];
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(mp[i][j] != 0){
				edge.to = j;
				edge.len = mp[i][j];
				p[i].push_back(edge);
			}
		}
	}
while(q --){
	x = read(),y = read();
	memset(flag,false,sizeof(flag));
	start.resize(0);
	end.resize(0);
	for(int i = 0;i < station[x].size();i ++){
		too = station[x][i].l;
		if(!flag[too]){
			start.push_back(too);
			flag[too] = true;
		}
	}
	memset(flag,false,sizeof(flag));
	for(int i = 0;i < station[y].size();i ++){
		too = station[y][i].l;
		if(!flag[too]){
			end.push_back(too);
			flag[too] = true;
		}
	}
	anss = INT_MAX;
	memset(ans,0x3f3f,sizeof(ans));
	for(int i = 0;i < start.size();i ++){
		stt = start[i];
		dfs(start[i],-1,0);
	}
//	for(int i = 1;i <= n;i ++){
//		for(int j = 0;j < p[i].size();j ++){
//			cout << p[i][j].to << " ";
//		}
//		cout << endl;
//	}
	cout << anss << endl;
//	for(int i = 0;i < start.size();i ++) cout << start[i] << " ";
//	cout << "\n";
//	for(int i = 0;i < end.size();i ++) cout << end[i] << " ";
//	cout << endl;
}
	return 0;
}
