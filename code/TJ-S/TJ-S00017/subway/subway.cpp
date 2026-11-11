#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long

LL c,n,m,d,q,w[5005],mapi[5005][5005];
bool map1[5005][5005];
struct node_subway{
	LL k,a[5005],t[5005];
}x[5005];

struct node_station{
	LL to_go[2][5005],used_time_sf,now_sub = 0,now_to_go = 0;
}y[5005];

void bfs(LL now,LL f,LL time){
	if(map1[time][f]) return ;
	map1[time][now] = true;
	for(int i = 1;i <= y[i].now_to_go;i++){
		if(map1[time][y[i].to_go[1][i]] == false){
			map1[time][y[i].to_go[1][i]] = true;
			mapi[time][y[i].to_go[1][i]] = mapi[time][now] + x[y[i].to_go[0][i]].t[now] + x[y[i].to_go[0][i]].t[y[i].to_go[1][i]];
			bfs(y[i].to_go[1][i],f,time);
		}
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(LL i = 1;i <= m;i++){
		cin>>w[i];
		y[i].used_time_sf = w[i];
	}
	for(LL i = 1;i <= n;i++){
		cin>>x[i].k;
		for(LL j = 1;j <= x[i].k;j++){
			cin>>x[i].a[j]>>x[i].t[j];
			y[x[i].a[j]].to_go[0][y[i].now_sub + 1] = i;
			y[i].now_sub++;
		}
		for(LL j = 1;j <= x[i].k;j++){
			for(LL g = 1;g <= x[i].k;g++){
				if(j == g) continue;
				y[x[i].a[j]].to_go[1][y[i].now_to_go + 1] = g;
				y[j].now_to_go++;
			}
		}
	}
	for(LL i = 1;i <= q;i++){
		LL start,finished;
		cin>>start>>finished;
		bfs(start,finished,i);
		cout<<y[start].used_time_sf + mapi[i][finished] + y[start].used_time_sf<<endl;
	}
	
	return 0;
}
