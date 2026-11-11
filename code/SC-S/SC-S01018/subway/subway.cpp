#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+5,N = 505,D = 25;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-'){
			f *= -1;
		}
		c = getchar();
	}
	while('0' <= c && c <= '9'){
		x = (x<<1)+(x<<3)+(c-'0');
		c = getchar();
	}
	return x*f;
}
char get_char(){
	char c = getchar();
	while((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))c = getchar();
	return c;
}
void write(long long x){
	if(x>=10)write(x/10);
	char c;
	c = x%10 + '0';
	putchar(c);
}
struct Stop{
	map<int,int>time_in_linestate;
	int num_of_line;
	int line[D];
}stop[M];
int c,n,m,d,q,trans[N][N];
int w[M],way[N],dist,answay[N];
long long ans = 1e18+5;
bool vis[N];
void dfs(int st,int last,int endd,int final,long long res){
//	printf("%dres:%d ",last,res);
	if(st == endd){
		res += (last == final?0:stop[last].time_in_linestate[endd] + stop[final].time_in_linestate[endd]);
//		printf("res:%d\n",res);
		if(res < ans){
			for(int i = 1;i <= dist;i++){
				answay[i] = way[i];
			}
			ans = res;
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		if(i == st)continue;
		if(vis[i])continue;
		if(trans[st][i]){
			vis[i]  = 1;
			way[++dist] = i;
			int state = trans[st][i];
			int cost = (last == state?0:stop[last].time_in_linestate[st] + stop[state].time_in_linestate[st]);
			dfs(i,state,endd,final,res+cost);
			vis[i] = 0;
			way[dist--] = 0;
		}
	}
}
long long get_answer(int st,int endd){
	long long res = 0;
	for(int i = 1;i <= stop[st].num_of_line;i++){
		int lin = stop[st].line[i];
		if(!stop[endd].time_in_linestate[lin])continue;
		res = stop[endd].time_in_linestate[lin]+stop[st].time_in_linestate[lin] + w[st]+w[endd];
		return res;
	}
	int st_line = stop[st].line[1],endd_line = stop[endd].line[1];
	way[++dist] = st_line,vis[st_line] = 1;
	dfs(st_line,st,endd_line,endd,0);
//	printf("%d %d",ans,w[st]+w[endd]);
//	for(int i = 1;answay[i];i++){
//		printf("%d ",answay[i]);
//	}
	res += ans;
	res += w[st]+w[endd];
	return res;
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i <= m;i++){
		w[i] = read();
	}
	for(int i = 1;i <= n;i++){
		int k = read(),state,time;
		for(int j = 1;j <= k;j++){
			state = read(),time = read();
			stop[state].time_in_linestate[i] = time;
			stop[state].num_of_line++;
			stop[state].line[stop[state].num_of_line] = i;
		}
	}
	for(int i = 1;i <= m;i++){
		if(stop[i].num_of_line >= 2){
			for(int j = 1;j < stop[i].num_of_line;j++){
				for(int k = j+1;k <= stop[i].num_of_line;k++){
					trans[stop[i].line[j]][stop[i].line[k]] = i;
					trans[stop[i].line[k]][stop[i].line[j]] = i;
				}
			}
		}
	}
	while(q--){
		int x = read(),y = read();
		memset(vis,0,sizeof(vis));
		memset(way,0,sizeof(way));
		memset(answay,0,sizeof(answay));
		dist = 0;
		write(get_answer(x,y));
		putchar('\n');
	}
	return 0;
}

