#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
const int N = 1e5 + 5;

int c,n,m,d,q;

struct subway{
	long long disc;
	long long diss[25];
	int next[45];
	int pos_n = 1;
	int rpos[45];
} sub[M];

struct route{
	long long snum;
	vector<int> sta;
}rou[M];

long long ans;
long long a,b;
bool vis[M];

bool dfs(int pos,int minn,int end,int ro){
	vis[pos] = true;
	if(pos == end){
		
		ans = min(ans,minn + sub[pos].diss[ro]);
		vis[pos] = false;
		return true;
		
	}
	
	for(int i = 1;i < sub[pos].pos_n;i++){
		int tmp2;
		if(ro == sub[pos].next[i]){
			tmp2 = 0;
		}
		else if(ro == -1){
			tmp2 = sub[pos].diss[i];
		}
		else{
			tmp2 = sub[pos].diss[ro] + sub[pos].diss[i];
		}
		
		if(sub[pos].rpos[i] + 1 < rou[sub[pos].next[i]].snum && vis[rou[sub[pos].next[i]].sta[sub[pos].rpos[i] + 1]] == false){
			
			dfs(rou[sub[pos].next[i]].sta[sub[pos].rpos[i] + 1],minn + tmp2,end,sub[pos].next[i]);
		}
		
		if(sub[pos].rpos[i] - 1 >= 0 && vis[rou[sub[pos].next[i]].sta[sub[pos].rpos[i] - 1]] == false){
			
			dfs(rou[sub[pos].next[i]].sta[sub[pos].rpos[i] - 1],minn + tmp2,end,sub[pos].next[i]);
		}

	}
	
	vis[pos] = false;
	return false;
}
void logic(){
	
	fill(vis,vis + M,false);
	dfs(a,0,b,-1);
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i = 1;i <= m;i++){
		cin>>sub[i].disc;
	}
	long long tmp = 0,tmp2 = 0;
	for(int i = 1;i <= n;i++){
		cin>>rou[i].snum;
		for(int j = 1;j <= rou[i].snum;j++){
			cin>>tmp;
			rou[i].sta.emplace_back(tmp);
			cin>>tmp2;
			sub[tmp].diss[i] = tmp2;
			sub[tmp].rpos[sub[tmp].pos_n] = j - 1;
			sub[tmp].next[sub[tmp].pos_n++] = i;
		}
	}
	

	while(q--){
		ans = 1e5;
		cin>>a>>b;
		logic();
		//一定要从大厅出去 
		ans += sub[a].disc;
		ans += sub[b].disc;
		
		cout<<ans<<endl;
	}
	return 0;
}

