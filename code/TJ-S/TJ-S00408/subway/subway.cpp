#include<bits/stdc++.h>
using namespace std;

struct st{
	long long to , use;
};

long long co , n , m , d , q;
long long a[500005];
long long b[505];
long long c[505];
long long f[1005][1005];
vector<st>e[1005];

void dfs(long long s , long long x){
	for(st h:e[x]){
		if(f[s][h.to] > f[s][x] + h.use){
			f[s][h.to] = f[s][x] + h.use;
			dfs(s , h.to);
		}
	}
}

int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	cin >> co >> m >> n >> d >> q;
	
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	if(n <= 400){
		for(long long i = 1;i <= n;i++){
			for(long long j = 1;j <= n;j++){
				if(i != j) f[i][j] = 1e9;
			}
		}
		
		for(long long i = 1;i <= m;i++){
			long long k;
			cin >> k;
			
			for(long long j = 1;j <= k;j++){
				cin >> b[j] >> c[j];
			}
			
			for(long long x = 1;x <= k;x++){
				for(long long y = x+1;y <= k;y++){
					f[b[x]][b[y]] = min(f[b[x]][b[y]] , c[x]+c[y]);
				}
			}
		}
		
		for(long long k = 1;k <= n;k++){
			for(long long i = 1;i <= n;i++){
				for(long long j = 1;j <= n;j++){
					if(i != j) f[i][j] = min(f[i][j] , f[i][k] + f[k][j]);
				}
			}
		}
		
		for(long long i = 1;i <= q;i++){
			long long x , y;
			cin >> x >> y;
			cout<<f[x][y]+a[x]+a[y]<<endl;
		}
	}else if(n <= 1000){
		for(long long i = 1;i <= m;i++){
			long long k;
			cin >> k;
			if(k == 2){
				long long x1 , x2 , w1 , w2;
				cin >> x1 >> w1 >> x2 >> w2;
				e[x1].push_back({x2 , w1+w2});
				e[x2].push_back({x1 , w1+w2});
			}else{
				long long x , w;
				cin >> x >> w;
			}
		}
		
		for(long long i = 1;i <= n;i++){
			for(long long j = 1;j <= n;j++){
				f[i][j] = 1e9;
			}
			f[i][i] = 0;
		}
		
		for(long long i = 1;i <= n;i++){
			dfs(i , i);
		}
		
		for(long long i = 1;i <= q;i++){
			long long x , y;
			cin >> x >> y;
			cout<<f[x][y]+a[x]+a[y]<<endl;
		}
	}
	return 0; 
} 

/* 这题数据怎么这么大啊，先打暴力
首先当只有<400个时，建个图再走floyd

行1-8写完
不是，这啥数据，我换行哪，你这咋把两个数合一起了

算了，先打下A，B写不出来
A就相当于一棵树加一条边
n=1000，用深搜有点难
要不加个记忆化试试
q次中，搜一次加一次记忆化 
*/
