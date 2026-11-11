#include <bits/stdc++.h>
using namespace std;
#define long long int
int c,n,m,d,q;
int w[100005] = {};
int sum;
struct node{
	int k;
	int a,t;
	int x,y;
}f[100005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> f[i].k;
		for(int j = 1;j <= f[i].k;j++){
			cin >> f[i].a >> f[i].t;
			f[f[i].a].t = f[i].t;
		}
	}
	int cnt = 0;
	int endd;
	for(int i = 1;i <= q;i++){
		cin >> f[i].x >> f[i].y;
	}
	for(int i = 1;i <= q;i++){
		cnt = f[i].x;
		endd = f[i].y;
		sum += w[cnt];
		for(int j = 1;j <= n;j++){
			for(int b = 1;b <= f[j].k;b++){
				sum += f[cnt].t;
				cnt++;
				if(cnt != f[b].a){
					break;
				}
				if(cnt == endd){
					goto end;
				}
			}
			end:
				sum += w[endd];
		}
		cout << sum - endd << endl;
		sum = 0;
	}
} 
