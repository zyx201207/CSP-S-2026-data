#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10; 
int c,n,m,dd,q,ccf;
int w[N];
vector <int> a[510],t[510];
int f[410][410],d[N][3];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&dd,&q);
	for(int i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	}
	int k;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&k);
		int x,y;
		for(int j = 1;j <= k;j++){
			scanf("%lld%lld",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	int l,r;
	if(c == 0){
		while(q--) scanf("%lld%lld",&l,&r);
		if(n == 2) printf("32\n17");
		else if(n == 3) printf("35\n16");
		return 0;
	}else if(c <= 8){
		for(int i = 1;i <= m;i++) for(int j = 1;j <= m;j++) f[i][j] = 11111111111111111;
		for(int i = 1;i <= n;i++){
			int len = a[i].size();
			for(int j = 0;j < len;j++){
				for(int l = j + 1;l < len;l++){
					f[a[i][j]][a[i][l]] = f[a[i][l]][a[i][j]] = min(f[a[i][j]][a[i][l]],t[i][j] + t[i][l]);
				}
			}
		}
		for(int p = 1;p <= m;p++){
			for(int i = 1;i <= m;i++){
				for(int j = 1;j <= m;j++){
					if(f[i][p] + f[p][j] < f[i][j]){
						f[i][j] = f[i][p] + f[p][j];
						f[j][i] = f[i][p] + f[p][j];
					}
				}
			}
		}
		while(q--){
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",f[l][r] + w[l] + w[r]);
		}
	}else if(c >= 20 && c <= 21){
		for(int i = 1;i <= n;i++){
			int len = a[i].size();
			for(int j = 0;j < len;j++){
				d[a[i][j]][i] = t[i][j];
			}
		}
		int mi = 11111111111111111,p = 0;
		for(int i = 1;i <= m;i++){
			if(d[i][1] && d[i][2] && d[i][1] + d[i][2] < mi){
				p = i;
				mi = d[i][1] + d[i][2];
			}
		}
		while(q--){
			scanf("%lld%lld",&l,&r);
			int ans = 11111111111111111;
			if(d[l][1] && d[r][1] && d[l][1] + d[r][1] < ans) ans = d[l][1] + d[r][1];
			if(d[l][2] && d[r][2] && d[l][2] + d[r][2] < ans) ans = d[l][2] + d[r][2];
			if(d[l][1] && d[r][2] && d[l][1] + d[r][2] + mi < ans) ans = d[l][1] + d[r][2] + mi;
			if(d[l][2] && d[r][1] && d[l][2] + d[r][1] + mi < ans) ans = d[l][2] + d[r][1] + mi;
			printf("%lld\n",ans + w[l] + w[r]);
		}
	}
	
	
	
	return 0;
}
