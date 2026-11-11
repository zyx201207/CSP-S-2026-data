#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],ways,minx;
int m[2000005];
stack<int>s;
void check(int x,int y,int times){
	m[x] = 1;
	if(x == y){
		minx = min(minx,times);
		s.push(times);
		return;
	}
	for(int i = x+1;i <= y;i++){
		if(a[i] - a[x] <= d){
			if(!m[x]) check(i,y,times+1);
		}
	}
	m[x] = 0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		int cnt = 0;
		for(int i = i;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				minx = 1e18;
				ways = 0;
				check(i,j,0); 
				while(!s.empty()){
					if(s.top() == minx) ways++;
					s.pop();
				}
				if(ways == 2) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
