//姓名:陆坦仪
//学校:西安市第三中学 
//考号:SN-S00524
#include<bits/stdc++.h>
using namespace std;
const int N = 1145;
#define PII pair<int,int>
int c,n,m,d,q,w[N] = {},st,ed;
int td[N] = {};//time_down 表示当前站点的上下时间
int num[N][N] = {};//由i到j的线路编号 
int tc[N][N] = {};//由i到j的站内换乘用时 
long long ans = 0;
int cnt = n;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >>n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> td[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			
		}
	}
	if(c >= 1 && c <= 6){
		while(q--){
			cin >> st >> ed;
			ans = ans + td[st] + td[ed];
			ans = ans + tc[st][ed];
			cout << ans << '\n';
		}
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
