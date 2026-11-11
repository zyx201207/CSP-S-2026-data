#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
//migrate
int c,T;
int n,r[N],r2[N];
ll d,x[N];
ll ans;
int flg[N];
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 1
8 3
0 1 2 4 8 10 11 13

*/

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	 
	cin >> c >> T;
	while(T --){
		cin >> n >> d;
		ans = 0;
		for(int i = 1;i <= n;i ++){
			cin >> x[i];
		}
		for(int R = 2;R <= n;R ++){
			int pos = 1;
			for(int i = 1;i <= R;i ++){
				while(pos + 1 <= R && x[pos + 1] - x[i] <= d){
					pos ++;
				}
				r[i] = pos;
			}
			pos = 1;
			for(int i = 2;i <= R;i ++){
				while(pos + 1 <= i && x[r[i]] - x[pos] > d){
					pos ++;
				}
				if(pos == i)flg[i] = 0;
				else if(pos == i - 1)flg[i] = 1;
				else flg[i] = 2;
			}
			for(int i = 1;i <= R;i ++){
				int now = i;
				while(r[now] != now){
					now = r[now];
				}
				if(now != R)flg[i] = 2;
			}
			for(int i = 1;i <= R;i ++){
				r2[i] = 0;
				int pos = r[i];
				while(pos < R){
					if(flg[pos] == 1){
						r2[i] = pos;
						break;
					}
					else if(flg[pos] == 2){
						break;
					}
					else{
						pos = r[pos];
					}
				}
			}	
			for(int i = 1;i < R;i ++){
				int to1 = r2[i],to2 = r2[r2[i]];
				if(to1 == 0)continue;
				if(to2 == 0 || to2 == R)ans ++;
			}
			for(int i = 1;i <= R;i ++){
				r[i] = r2[i] = flg[i];
			}
		}
		cout << ans << "\n";
	}
	
	
	
	return 0;
} 
