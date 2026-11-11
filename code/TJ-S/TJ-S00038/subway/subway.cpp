#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 510;
const int M = 5*1e5+10;
int c,n,m,d,q;
int w[M];

int coss[M];

struct Node{
	int end;
	int len;
};
Node eds[M][20];

LL e[N][N];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i != j) e[i][j] = -1;
		}
	}
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int ai,ti,ki;
		cin >> ki;
		for(int j = 0;j < ki;j++){
			cin >> ai >> ti;
			coss[ai]++;
			eds[ai][coss[ai]-1].end = i;
			eds[ai][coss[ai]-1].len = ti;
		}
	}
	
	for(int i = 1;i <= m;i++){
		if(coss[i] < 2) continue;
		for(int j = 0;j < coss[i];j++){
			for(int k = 0;k < coss[i];k++){
				if(j == k) continue;
				e[eds[i][j].end][eds[i][k].end] = e[eds[i][k].end][eds[i][j].end] = (long long)(eds[i][j].len)+eds[i][k].len;
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(e[i][k] == -1 || e[k][j] == -1) continue;
				if(e[i][j] != -1)
					e[i][j] = min(e[i][j],e[i][k]+e[k][j]);
				else
					e[i][j] = e[i][k]+e[k][j];
			}
		}
	}
	
	for(int i = 0;i < q;i++){
		int st,ed;
		cin >> st >> ed;
		LL ansmin = -1;
		for(int j = 0;j < coss[st];j++){
			for(int k = 0;k < coss[ed];k++){
				if(ansmin == -1)
					ansmin = e[eds[st][j].end][eds[ed][k].end]+eds[st][j].len+eds[ed][k].len+w[st]+w[ed];
				else
					ansmin = min(ansmin,e[eds[st][j].end][eds[ed][k].end]+eds[st][j].len+eds[ed][k].len+w[st]+w[ed]);
			}
		}
		cout << ansmin << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
