#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int c,n,m,d,q;
priority_queue <int,vector<int>,greater<int> > p;
int w[N];
int a[N][N];

void cleanp(){
	while(!p.empty()){
		p.pop();
	}
}

//st初始站,ed终点站,z当前站点,val价值 
void dfs(int st,int ed,int z,int val){
	if(z > ed) return ;
	if(z == ed) p.push(val + w[st] + w[ed]);
	for(int i = 1;i <= m;i++){
		if(a[z][i] != 0) dfs(st,ed,i,val+a[z][i]);
	}
}

int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		int zb[N],jz[N];
		for(int j = 1;j <= k;j++){
			cin >> zb[j] >> jz[j];
		}
		for(int j = 1;j < k;j++){
			a[zb[j]][zb[j+1]] = jz[j] + jz[j+1];
		}
	}
	for(int i = 1;i <= q;i++){
		int xr,yr;
		cin >> xr >> yr;
		cleanp();
		dfs(xr,yr,xr,0);
		cout << p.top() << endl;
	}

	return 0;
}

