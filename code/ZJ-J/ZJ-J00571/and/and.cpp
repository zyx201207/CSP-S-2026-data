#define ll long long

#include<bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 10;
int a[mx];
int f[mx][40],s[40];
int sg[40];
int st[mx],g[mx];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++){
		int k = a[i];
		int t = -1;
		while(k > 0){
			f[i][++t] = k % 2;
			k /= 2;
		}
	}
	for(int i = 0;i <= 35;i++){
		for(int j = 1;j <= n;j++){
			s[i] += f[j][i];
		}
	}
	int x;
	for(int i = 35;i >= 0;i--){
		if(s[i] >= m){
			x = i;
			break;
		}
	}
	int t = 0;
	int h = 0;
	for(int i = 1;i <= n;i++){
		if(f[i][x] == 1){
			t++;
			st[++h] = i;
			g[h] = 1;
			for(int j = 0;j <= 35;j++){
				sg[j] += f[i][j];
			}
		}
	}
	int l = x - 1;
	while(t > m && l >= 0){
		if(sg[l] >= m){
			for(int i = 1;i <= h;i++){
				if(f[st[i]][l] == 0 && t > m && g[i] == 1){
					t--;
					g[i] = 0;
					for(int j = 0;j <= 35;j++)sg[j] -= f[st[i]][j];
				}else if(t == m){
					break;
				}
			}
		}
		l--;
	}
	int ans = 0;
	for(int i = 1;i <= h;i++){
		if(g[i] == 0)continue;
		if(ans == 0)ans = a[st[i]];
		else ans = ans & a[st[i]];
	}
	printf("%d",ans);
	return 0;
}
